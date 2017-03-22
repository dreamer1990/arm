
#include "res.h"


	//mmu => VMSA  virtual Memory System Architector
	//VMSA ==> System Controller  ==> cp15
	//协处理器   cp15  coprocessor
	//DRAM地址  0x40000000 -> 0x80000000
	//iram irom 板子内部地址 0x00000000 -> 0x10000000
	//SFR       0x10000000 -> 0x14000000
	
void init_ttb(unsigned int *ttb)
{
	unsigned int Pa , Va ; 
	//1.irom iram 
	for(Va = 0x00000000 ; Va < 0x10000000 ; Va+=0x100000)
	{
		Pa = Va ; 
		ttb[Va>>20] = (Pa&(0xFFF<<20)) | 2 ; 
	}
	//SFR 地址
	for(Va = 0x10000000 ; Va < 0x14000000 ; Va+=0x100000)
	{
		Pa = Va ; 
		ttb[Va>>20] = (Pa&(0xFFF<<20)) | 2 ; 
	}
	//DRAM
	for(Va = 0x40000000 ; Va < 0x80000000 ; Va+=0x100000)
	{
		Pa = Va ; 
		ttb[Va>>20] = (Pa&(0xFFF<<20)) | 2 ; 
	}
}
void mmap(unsigned int *ttb , unsigned int Pa , unsigned int Va)
{
		ttb[Va>>20] = (Pa&(0xFFF<<20)) | 2 ; 
}


void enable_mmu(void)
{
	unsigned int Pa = 0x5FFF0000; 
	unsigned int Va = 0xFFFF0000; 

	unsigned int ttb = 0x61000000 ; 


	//*******************************
	//1.清ttb地址16K空间 
	memset((char *)ttb , 0 , 16*1024);

	//2.映射自己的内存表
	init_ttb((unsigned int*)ttb);

	//3.映射空间
	mmap((unsigned int *)ttb , Pa , Va);

	unsigned int sysctrl = 1 | (1 << 11) | (1 << 13);
	//4.set ttb
	__asm__ __volatile__ (


	//1>set domain permission
	//"mvn	r0 , #0			    \n"
	"ldr	r0 , =0xFFFFFFFF    \n"
	"MCR p15, 0, r0, c3, c0, 0  \n"

	//2>set ttb table
	"mov	r0 , %0             \n"
	"MCR p15, 0, r0, c2, c0, 0  \n"

	//3>enable mmu  system control register  sctl
	"MRC p15, 0, r0, c1, c0, 0  \n"
	"mov	r1 , %1             \n"
	"orr	r0 , r0 , r1        \n"
	"MCR p15, 0, r0, c1, c0, 0  \n"
	::"r"(ttb),"r"(sysctrl)
	:"r0","r1"
	);

}
