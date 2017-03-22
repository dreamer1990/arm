
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

	enable_external_irq(11 , TRIGGER_BOTH_EDGE);
	
	enable_TIMER();

#if 0
	//不成立  不成立原因是该IO口的电压为1.8V 不足以驱动超声波模块
	//set gpj0_3
	#define  GPJ0CON  *(U32 *)0x11400240
	#define  GPJ0DAT  *(U32 *)0x11400244
	GPJ0CON &= ~(0xF << 12) ;
	GPJ0CON |= 0x1 << 12 ; 
#endif
	//可以  3.3V
	GPD0CON &= ~0xF ; 
	GPD0CON |= 0x1 ; 

	while(1)
	{
		//GPJ0DAT |= 1 << 3 ; 
		GPD0DAT |= 1 ;
		udelay(100);
		//GPJ0DAT &= ~(1 << 3);
		GPD0DAT &= ~1 ; 
		udelay(100000);
	}


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
	static int count = 0 ; 
	unsigned int val ; 
	val = ICCIAR_CPU0 ; 
	//printf("this is do_Irq... val:%d id:%d \n" , val , val&0x3FF);

	if(EXT_INT41_PEND & (1 << 3))
	{
	//	printf("haha ... \n");
	//printf("count:%d \n" , count);	
	//	printf("Distant:%d cm\n" , count*17);
		#define  GPX1DAT  *(U32 *)0x11000C24
		if(GPX1DAT&(0x1<<3))
		{
			start_timer();
			count = 0 ; 
		}else
		{
			stop_timer();
			printf("Distant:%d cm\n" , count*17);
			//count = 0 ; 
		}
		//stop_timer();
		//start_timer();
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
		//printf("tick ... \n");
		count++ ; 
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
