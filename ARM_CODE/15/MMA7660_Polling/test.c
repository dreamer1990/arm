
#include "res.h"
#include "irq.h"
#include "i2c.h"
#include "basedevice.h"
#include "timer.h"

static int (*printf)(const char *fmt , ...) = (void *)0x43e11a2c ;
static void (*udelay)(unsigned int usec) = (void *)0x43e26480;

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

	//1.产生一个中断  14外部中断 确定触发方式
//	enable_external_irq(14 , TRIGGER_FALLING_EDGE);

	GPIO_Init();
	I2C_InitIp(I2C3 , 200000 , 0);
	#define  SLAVEADDR  (0x4C<<1)
	char Buf[10] ;


	char Addr[1] = {0x07};
	char Data[1] = {0x04};
	//设置成测试模式  不能直接从测试模式进入Active模式 test=>standby=>active
	//测试模式只能动4寄存器 x y z mode
	I2C_SendForGeneral(I2C3 , SLAVEADDR, Addr , 1 ,Data , 1 );


	//进入standby模式 ,配置其它寄存器必须进入standby模式才能配置
	Addr[0] = 0x7 ; 
	Data[0] = 0x0 ; 
	I2C_SendForGeneral(I2C3 , SLAVEADDR, Addr , 1 ,Data , 1 );

	//配置auto-sleep的采样率
	Addr[0] = 0x8 ; 
	Data[0] = 0x0 ;   //set 120次/s
	I2C_SendForGeneral(I2C3 , SLAVEADDR, Addr , 1 ,Data , 1 );


	//设置成Active模式  且进入auto-sleep mode
	Addr[0] = 0x7 ; 
	Data[0] = 0x11 ; 
	I2C_SendForGeneral(I2C3 , SLAVEADDR, Addr , 1 ,Data , 1 );


	while(1)
	{
		I2C_Recv(I2C3 , SLAVEADDR ,Buf , 10 );
		printf("x:%5d y:%5d z:%5d \n" , Buf[0]&0xFF , Buf[1]&0xFF , Buf[2]&0xFF);
	}

#if 0
	I2C_Recv(I2C3 , SLAVEADDR ,Buf , 10 );
	//读取偏移量设置没有用,也就说该设备不支持
	//I2C_RecvForGeneral(I2C3 , SLAVEADDR , Addr , 1 , Buf , 10);

	int i ; 
	for(i = 0 ; i < 10 ; i++)
	{
		printf("Buf[%d]:%p \n" , i , Buf[i]&0xFF);
	}
#endif

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
	//printf("this is do_Irq... val:%d id:%d \n" , val , val&0x3FF);
	
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

	if(EXT_INT43_PEND & (1 << 2))
	{
		printf("frist key press ... \n");
		EXT_INT43_PEND = EXT_INT43_PEND ; 
	}
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

	//处理完
	ICCEOIR_CPU0 = val ; 
}
void do_Fiq(void)
{
	printf("this is do_Fiq... \n");
}
