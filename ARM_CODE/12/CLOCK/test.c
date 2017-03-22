
#include "res.h"
#include "irq.h"
#include "basedevice.h"
#include "timer.h"

int (*printf)(const char *fmt , ...) = (void *)0x43e11a2c ;
void (*udelay)(unsigned int usec) = (void *)0x43e26480;

void do_Reset(void);
void do_Undef(void);
void do_Svc(void);
void do_PrefetchAbt(void);
void do_DataAbt(void);
void do_Irq(void);
void do_Fiq(void);



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

	//APLL PMS value  3 175 0  1.4G
	#define   APLL_CON0   *(U32 *)0x10044100
	printf("APLL P:%d  M:%d  S:%d  \n" , (APLL_CON0>>8)&0x3F , (APLL_CON0>>16)&0x3FF , APLL_CON0 & 0x7);

	//MPLL PMS value  3 100 0  800M
	#define   MPLL_CON0   *(U32 *)0x10040108
	printf("MPLL P:%d  M:%d  S:%d  \n" , (MPLL_CON0>>8)&0x3F , (MPLL_CON0>>16)&0x3FF , MPLL_CON0 & 0x7);

	
	//EPLL PMS value 2 64  3  96M
	#define   EPLL_CON0   *(U32 *)0x1003C110
	printf("EPLL P:%d  M:%d  S:%d  \n" , (EPLL_CON0>>8)&0x3F , (EPLL_CON0>>16)&0x3FF , EPLL_CON0 & 0x7);

	//VPLL PMS value 2 72 3   108M
	#define   VPLL_CON0   *(U32 *)0x1003C120
	printf("VPLL P:%d  M:%d  S:%d  \n" , (VPLL_CON0>>8)&0x3F , (VPLL_CON0>>16)&0x3FF , VPLL_CON0 & 0x7);

	//APLL  MUX
	#define  CLK_SRC_CPU    *(U32 *)0x10044200
	printf("MUX_MPLL_USER_SEL_C:%d \n" , (CLK_SRC_CPU>>24)&0x1);
	printf("MUX_HPM_SEL:%d \n" , (CLK_SRC_CPU>>20)&0x1);
	printf("MUX_CORE_SEL:%d \n" , (CLK_SRC_CPU>>16)&0x1);
	printf("MUX_APLL_SEL:%d \n" , (CLK_SRC_CPU)&0x1);
	
	//RATIO
	#define  CLK_DIV_CPU0  *(U32 *)0x10044500
	#define  CLK_DIV_CPU1  *(U32 *)0x10044504
	
	printf("CORE_RATIO:%d\n" , (CLK_DIV_CPU0>>0)&0x7);
	printf("COREM0_RATIO:%d\n" , (CLK_DIV_CPU0>>4)&0x7);
	printf("COREM1_RATIO:%d\n" , (CLK_DIV_CPU0>>8)&0x7);
	printf("PERIPH_RATIO:%d\n" , (CLK_DIV_CPU0>>12)&0x7);
	printf("ATB_RATIO:%d\n" , (CLK_DIV_CPU0>>16)&0x7);
	printf("PCLK_DBG_RATIO:%d\n" , (CLK_DIV_CPU0>>20)&0x7);
	printf("APLL_RATIO:%d\n" , (CLK_DIV_CPU0>>24)&0x7);
	printf("CORE2_RATIO:%d\n" , (CLK_DIV_CPU0>>28)&0x7);

	printf("COPY_RATIO:%d\n" , (CLK_DIV_CPU1>>0)&0x7);
	printf("HPM_RATIO:%d\n" , (CLK_DIV_CPU1>>4)&0x7);
	printf("CORES_RATIO :%d\n" , (CLK_DIV_CPU1>>8)&0x7);

	//**********************************
	//串口时钟

	#define  CLK_DIV_PERIL0  *(U32 *)0x1003C550
	printf("DIV_PERIL0:%p \n" , CLK_DIV_PERIL0);

	#define  CLK_DIV_LCD     *(U32 *)0x1003C534
	printf("CLK_DIV_LCD:%p \n" , CLK_DIV_LCD);

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

