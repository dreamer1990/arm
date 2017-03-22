
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

void enable_external_irq(int irqno ,int Trigger_Mode )
{
	//参数检查
	if((irqno < 0) || (irqno > 31))
		return ; 
	
	//开启内部中断
	if(irqno >= 16)
		enable_internal_irq(64);
	else
		enable_internal_irq(48+irqno);

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
	*(U32 *)(0x11000E00+((irqno/8)<<2))  &= ~(0xF << ((irqno&0x7)<<2)) ; 
	*(U32 *)(0x11000E00+((irqno/8)<<2))  |= (Trigger_Mode << ((irqno&0x7)<<2)) ; 
	//EXT_INT43_CON &= ~(0xF << 8) ; 
	//EXT_INT43_CON |= 0x2 << 8 ; 
	
	//2>配置使能
	*(U32 *)(0x11000F00+((irqno/8)<<2))  &= ~(1 << (irqno&0x7));
	//EXT_INT43_MASK  &= ~(1 << 2) ; 

	//3>设置过滤器
	*(U32 *)(0x11000E80+((irqno/4)<<2)) |= 0xFF << ((irqno&0x3)<<3) ; 
	//EXT_INT43_FLTCON0 |= 0xFF << 16 ; 

	//3.配置IO中断模式
	//GPX3CON |= 0xF << 8 ;   //GPX3_2
	*(U32 *)(0x11000C00+(irqno/8)*0x20) |= 0xF << ((irqno&0x7)<<2) ; 
}
