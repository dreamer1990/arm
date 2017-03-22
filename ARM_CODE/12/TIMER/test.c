
#include "res.h"
#include "irq.h"
#include "basedevice.h"

int (*printf)(const char *fmt , ...) = (void *)0x43e11a2c ;
void (*udelay)(unsigned int usec) = (void *)0x43e26480;

void do_Reset(void);
void do_Undef(void);
void do_Svc(void);
void do_PrefetchAbt(void);
void do_DataAbt(void);
void do_Irq(void);
void do_Fiq(void);

void enable_PWM(void);


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

#if 0
	enable_external_irq(26 , TRIGGER_FALLING_EDGE);
	enable_external_irq(27 , TRIGGER_FALLING_EDGE);
	enable_external_irq(28 , TRIGGER_FALLING_EDGE);
	enable_external_irq(29 , TRIGGER_FALLING_EDGE);
#endif
	
	enable_internal_irq(69);

	//enable_PWM();
	//1.配置第一分频
	TCFG0 &= ~0xFF ; 
	TCFG0 |= 99 ;    //100M/(99+1)  ==> 1M
	
	//2.配置第二分频
	TCFG1 &= ~0xF ;
	
	//3.auto-reload
	TCON |= 1 << 3 ;

	//4.TCNTB 
	TCNTB0 = 1000000 -1; 

	//5.manual update
	TCON |= 1 << 1 ; 
	
	//6.clear manual update
	TCON &= ~(1 << 1) ; 

	//7.开启定时器中断
	TINT_CSTAT |= 1  ; 

	//start timer
	TCON |= 1 ; 

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


	//处理完
	ICCEOIR_CPU0 = val ; 
}
void do_Fiq(void)
{
	printf("this is do_Fiq... \n");
}


void enable_PWM(void)
{


	//1.配置第一分频
	TCFG0 &= ~0xFF ; 
	TCFG0 |= 99 ;    //100M/(99+1)  ==> 1M
	
	//2.配置第二分频
	TCFG1 &= ~0xF ;
	
	//3.auto-reload
	TCON |= 1 << 3 ;

	//4.TCNTB  TCMPB
	TCNTB0 = 1000000 -1; 
	TCMPB0 = 800000 - 1 ; 

	//5.manual update
	TCON |= 1 << 1 ; 
	
	//6.clear manual update
	TCON &= ~(1 << 1) ; 

	//7.invert-on
	TCON |= 1 << 2 ;

	//start timer
	TCON |= 1 ; 

	//set ip as PWM_TOUT0
	GPD0CON &= ~0xF ; 
	GPD0CON |= 0x2 ; 


}
