
#include "res.h"
#include "basedevice.h"

int (*printf)(const char *fmt , ...) = (void *)0x43e11a2c ;
void (*udelay)(unsigned int usec) = (void *)0x43e26480;
void vector_copy(void);

void do_Reset(void);
void do_Undef(void);
void do_Svc(void);
void do_PrefetchAbt(void);
void do_DataAbt(void);
void do_Irq(void);
void do_Fiq(void);

void enable_cpsr_I(void);

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

	//1.使能GIC
	ICCICR_CPU0 |= 1 ; 
	//2.使能Distributor
	ICDDCR  |= 1 ; 
	//3.CPU接收中断优先级
	ICCPMR_CPU0 |= 0xFF ; 
	
	//假设中段id为5
	//4.配置中断优先级
	ICDIPR1_CPU0 &= ~(0xFF << 8);
	//5.配置中断ID
	ICDISER0_CPU0 |= 1 << 5 ; 
	//6.配置目标CPU
	ICDIPTR1_CPU0 |= 0xF ; 


	//7.发送一个中断

	ICDSGIR |= (0xF << 16 ) | 5 ; 

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

	printf("this is do_Irq... val:%d \n" , val);



	//处理完
	ICCEOIR_CPU0 = val ; 
}
void do_Fiq(void)
{
	printf("this is do_Fiq... \n");
}

void vector_copy(void)
{
	extern void start(void);
	extern void end(void);

	unsigned int offset = (unsigned int)end - (unsigned int)start;

	//printf("offset:%d \n" , offset);

	memcpy((char *)0x5FFF0000 , (char *)start , offset+200);
}

void enable_cpsr_I(void)
{	
	__asm__ __volatile__ (
	"mrs  r0 , cpsr    \n"  //mov  register  spsr
	"bic	r0 , #(1 << 7)   \n"
	"msr  cpsr , r0    \n"  //mov  spsr  register
	);
}

