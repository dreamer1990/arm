
#include "irq.h"

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

void enable_internal_irq(int irqid)
{

	//1.使能GIC
	ICCICR_CPU0 |= 1 ; 
	//2.使能Distributor
	ICDDCR  |= 1 ; 
	//3.CPU接收中断优先级
	ICCPMR_CPU0 |= 0xFF ; 
	
	//4.配置中断优先级
	//ICDIPR1_CPU0 &= ~(0xFF << 8);
	*(U32 *)(icdbase + 0x400 + (irqid&(~(0x3)))) &= ~(0xFF << ((irqid&0x3)<<3));

	//5.配置中断ID
	//ICDISER0_CPU0 |= 1 << 5 ; 
	*(U32 *)(icdbase + 0x100 + irqid/32*4) |= 1 << (irqid%32);
	
	//6.配置目标CPU
	//ICDIPTR1_CPU0 |= 0xF ; 
	*(U32 *)(icdbase + 0x800 + (irqid&(~(0x3)))) |= (0xF << ((irqid&0x3)<<3));

}
void Send_internal_irq(int irqid)
{
	ICDSGIR |= (0xF << 16 ) | irqid ; 
}
