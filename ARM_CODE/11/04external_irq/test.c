
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

	//开启内部中断
	
	//传中断ID  1.配置内部中断
	enable_internal_irq(64);

	//2.配置外部中断
	//外部中断 外部中断控制寄存器  CON  PEND  MASK  FILTER
	//CON  配置中断触发类型  
	//PEND 检查中断状态 或者清中断
	//MASK 中断的掩码 使能
	//FILTER 过滤器
	
	//0x0 = Low level 
    //0x1 = High level 
    //0x2 = Triggers Falling edge 
    //0x3 = Triggers Rising edge 
    //0x4 = Triggers Both edge 

	//1>配置触发方式
	EXT_INT43_CON &= ~(0xF << 8) ; 
	EXT_INT43_CON |= 0x2 << 8 ; 
	
	//2>配置使能
	EXT_INT43_MASK  &= ~(1 << 2) ; 

	//3>设置过滤器
	EXT_INT43_FLTCON0 |= 0xFF << 16 ; 

	//3.配置IO中断模式
	GPX3CON |= 0xF << 8 ;   //GPX3_2

	//7.发送一个中断
	//Send_internal_irq(7);

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

	if(EXT_INT43_PEND & (1 << 2))
	{
		printf("key press ... \n");
		EXT_INT43_PEND = EXT_INT43_PEND ; 
	}


	//处理完
	ICCEOIR_CPU0 = val ; 
}
void do_Fiq(void)
{
	printf("this is do_Fiq... \n");
}
