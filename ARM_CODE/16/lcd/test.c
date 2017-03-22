
#include "res.h"
#include "irq.h"
#include "i2c.h"
#include "basedevice.h"
#include "timer.h"
#include "bmp.h"

static int (*printf)(const char *fmt , ...) = (void *)0x43e11a2c ;
static void (*udelay)(unsigned int usec) = (void *)0x43e26480;
static unsigned int PicAddr = 0x63000000 ; 

void do_Reset(void);
void do_Undef(void);
void do_Svc(void);
void do_PrefetchAbt(void);
void do_DataAbt(void);
void do_Irq(void);
void do_Fiq(void);
char Buffer[32] = {0};


int _start(void)
{
	*(U32 *)0x62000000 = (U32)do_Reset ; 
	*(U32 *)0x62000004 = (U32)do_Undef;
	*(U32 *)0x62000008 = (U32)do_Svc;
	*(U32 *)0x6200000C = (U32)do_PrefetchAbt;
	*(U32 *)0x62000010 = (U32)do_DataAbt;
	*(U32 *)0x62000014 = (U32)do_Irq;
	*(U32 *)0x62000018 = (U32)do_Fiq;
	//开启mmu
	enable_mmu();
	//拷中断向量表
	vector_copy();
	//清掉 cpsr 的中断掩码位
	enable_cpsr_I();

	//enable_internal_irq(84);
	enable_external_irq(26 , TRIGGER_FALLING_EDGE);


	//控制LCD时钟为  SCLK_FIMD0
	//1.查看当时时钟为多少 
	#define   CLK_DIV_LCD  *(U32 *)0x1003C534
	printf("FIMD0_RATIO:%d \n" ,  CLK_DIV_LCD&0xF);
	CLK_DIV_LCD &= ~0xF ;
	//CLK_DIV_LCD |= 3 ;  //100M
	
	//2.配置总开关  FIMD bypass
	#define  LCDBLK_CFG    *(U32 *)0x10010210	
	LCDBLK_CFG &= ~(0x3 << 10) ;
	LCDBLK_CFG |= 1 << 1 ; 

	//3.配置GPIO为LCD模式
	// GPF0 -> GPF3
	
	#define   GPF0CON      *(U32 *)0x11400180
	#define   GPF1CON      *(U32 *)0x114001A0
	#define   GPF2CON      *(U32 *)0x114001C0
	#define   GPF3CON      *(U32 *)0x114001E0

	GPF0CON = 0x22222222 ; 
	GPF1CON = 0x22222222 ; 
	GPF2CON = 0x22222222 ; 
	GPF3CON &=~0xFFFFFF ; 
	GPF3CON |= 0x222222 ; 

	//配置方法
	//The registers you can use to configure display controller are:
	//1. VIDCON0: Configures video output format 
	//1> RGB interface
		VIDCON0 &=~( 0x7 << 26 ) ; 
	//2> Selects display mode   RGB parallel format
		VIDCON0 &=~( 1 << 18 ) ; 
	//3> Controls inverting RGB_ORDER  返转RGB格式  Normal 
		VIDCON0 &=~( 1 << 17 );
	//4> Selects CLKVAL_F update timing control  Always
		VIDCON0 &=~( 1 << 16 );
	//5> Determines rates of VCLK ==> DCLK
		VIDCON0 &=~( 0xFF << 6);
		VIDCON0 |= 1 << 6 ; 
	//6> Controls VCLK Free Run (only valid at RGB IF mode). NORMAL
		VIDCON0 &=~( 1 << 5 );
	
	//2. VIDCON1: Specifies RGB I/F control signal.
	//1> VCLK running
		VIDCON1 &=~( 0x3 << 9) ; 
		VIDCON1 |= 1 << 9 ;   //VCLK RUNNING
	//2> Controls polarity of the VCLK active edge ==> Rising edge
		VIDCON1 |= 1 << 7 ; 
	//3> invert HSYNC
		VIDCON1 |= 1 << 6 ; 
	//4> invert VSYNC 
		VIDCON1 |= 1 << 5 ; 
	//5> VDEN not invert
		VIDCON1 &=~( 1 << 4 ); 

	//3. VIDCON2: Specifies output data format control.
	//disable skip   disable dummy insertion  nomal RGB 
		VIDCON2 = 1 << 14 ; 

	//4. VIDCON3: Specifies image enhancement control.
	//No Image Enhancement
	

	//6. VIDTCONx: Configures video output timing and determines the size of display.
	VIDTCON0 = (12 << 16)|(21 << 8)|9 ; 
	VIDTCON1 = (25 << 16)|(209 << 8)|19 ; 
	VIDTCON2 = (479 << 11) | (799) ; 

	
	//7. WINCONx: Specifies each window feature setting.
	//1>select RGB
		WINCON0 &= ~(1 << 13) ;
	//2>Selects DMA Burst Maximum Length  最大效率最高
		WINCON0 &= ~(0x3 <<9) ; 
	//3>Selects Bits Per Pixel(BPP)  8:8:8 24 RGB
		WINCON0 &= ~(0xF << 2) ;
		WINCON0 |= 0xb << 2 ; 
	//4>enable window 0
		WINCON0 |= 1 ; 

	//22. SHADOWCON: Specifies shadow control register.
	//Enables Channel 0. 
		SHADOWCON |= 1 ; 

	//8. VIDOSDxA, VIDOSDxB: Specifies window position setting.
	//1> left top 0:0
	VIDOSD0A = 0 ; 
	VIDOSD0B = (800<<11) | (480) ;
	//9. VIDOSDxC, D: Specifies On Screen Display (OSD) size setting.
	VIDOSD0C = 480*800 ; 
	
	//12. VIDWxxADDx: Specifies source image address setting.
	//指定图片地址
	VIDW00ADD0B0 = PicAddr ;   //起始地址
	VIDW00ADD1B0 = PicAddr + 800*480*4 ; 
	VIDW00ADD2   = 800*4 ; 

	//初始化图片
	int row  , col ; 
	#define RGB(r,g,b)   (((r)<<16)|((g)<<8)|(b))
	int i ; 
	for(i = 0 ; i < picturecount ; i++)
	{
		for(row = 0 ; row < 480 ; row++)
		{
			for(col = 0 ; col < 800 ; col++)	
			{
		((U32 *)PicAddr)[row*800+col+i*800*480] = BMP[row*800+col+i*800*480];
			}
		}
	}

	//保证在最后  displays enable/disable. display on
	VIDCON0 |= 0x3 ; 

	return 0 ; 
}


void do_Reset(void)
{
	printf("this is reset ... \n");
}
void do_Undef(void)
{
	printf("this is do_Undef... \n");
}
void do_Svc(void)
{
	printf("this is do_Svc ... \n");
}
void do_PrefetchAbt(void)
{
	printf("this is do_PrefetchAbt... \n");
}
void do_DataAbt(void)
{
	printf("this is do_DataAbt... \n");
}


void do_Irq(void)
{
	unsigned int val ; 
	val = ICCIAR_CPU0 ; 
	printf("this is do_Irq... val:%d id:%d \n" , val , val&0x3FF);
	
#if 0
	int i ; 
	if(EXT_INT41_PEND & (1 << 6))
	{
		//4.开始配置i2c的主体逻辑  读取i2c的数据
		//Read_I2c_Data(0x11 , Buffer ,32);
		I2C_Recv(I2C1 , 0x38 << 1, Buffer , 32 );
		printf("num:%d ********\n" , Buffer[2]&0xF );
		for(i = 0 ; i < Buffer[2]&0xF ; i++)
		{
			printf("i:%3d x:%5d y:%5d \n" ,i , ((Buffer[3+i*6]&0xF)<<8)|Buffer[4+i*6] , ((Buffer[5+i*6]&0xF)<<8)|Buffer[6+i*6] );
		}
	 	//
		EXT_INT41_PEND = EXT_INT41_PEND ; 
	}
	
	char Buf[10] ; 
	//25
	if(EXT_INT43_PEND & (1 << 1))
	{
		printf("interrupt ... \n");
		I2C_Recv(I2C3 , SLAVEADDR ,Buf, 10);
		//printf("x:%5d y:%5d z:%5d \n" , Buf[0]&0xFF , Buf[1]&0xFF , Buf[2]&0xFF);
		EXT_INT43_PEND = EXT_INT43_PEND ; 
	}
#endif

	if(EXT_INT43_PEND & (1 << 2))
	{
		static int i = 0 ; 
		
		VIDW00ADD0B0 = PicAddr +i*800*480*4;   //起始地址
		VIDW00ADD1B0 = PicAddr +(i+1)*800*480*4 ; 

		i = (i + 1)%picturecount ; 

		printf("frist key press ... \n");
		EXT_INT43_PEND = EXT_INT43_PEND ; 
	}
#if 0
	if(EXT_INT43_PEND & (1 << 3))
	{
		printf("second key press ... \n");
		EXT_INT43_PEND = EXT_INT43_PEND ; 
	}
	if(EXT_INT43_PEND & (1 << 4))
	{
		printf("third key press ... \n");
		EXT_INT43_PEND = EXT_INT43_PEND ; 
	}
	if(EXT_INT43_PEND & (1 << 5))
	{
		printf("fourth key press ... \n");
		EXT_INT43_PEND = EXT_INT43_PEND ; 
	}

	if(TINT_CSTAT & (1 << 5))
	{
		printf("tick ... \n");
		TINT_CSTAT |= 1 << 5 ;
	}
	
	//adc
	if(ISTR2 & (1 << 19))
	{
		if(ADCCON & (1 << 15))
		{
		printf("ADCDAT:%#5x \n" , ADCDAT&0xFFF);
		}
		ADCCON |= 1 ; 
		//清中断
		CLRINTADC = 0 ; 
	}
#endif

	//处理完
	ICCEOIR_CPU0 = val ; 
}
void do_Fiq(void)
{
	printf("this is do_Fiq... \n");
}
