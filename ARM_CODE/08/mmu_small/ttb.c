#include <config.h>
#include <string.h>

void ttb_init(u32 *ttb)
{
    memset(ttb, 0, 4096 * 4);       //初始化映射表;
    u32 i;
    /*
    //u-boot的代码本身:(运行环境) printf delay ...  0x43e00000 - xxx
    //stack 内存地址;  (p 指向栈的空间)             xxx - 0x42e00000 fd
    for(i = 0x42000000; i < 0x44000000; i+=0x100000)    //平板映射; 物理地址==虚拟地址
        ttb[i >> 20] = (i & 0xff000000) | (1<<18) | (0<<5) | 2; 
    
    //当前代码本身的.text .rodata .data .bss 
    ttb[0x500] = (0x500<<20)|(0<<18)|(0<<5)|2;
    */

    //DDR 内存平板映射;
    for(i = 0x40000000; i < 0x80000000; i+=0x100000)
        ttb[i >> 20] = (i & 0xfff00000) | (0<<18) | (0<<5) | 2; 

    //SFR 所有寄存器映射;
    for(i = 0x10000000; i < 0x14000000; i+=0x100000)
        ttb[i >> 20] = (i & 0xfff00000) | (0<<18) | (0<<5) | 2;

}

void ttb_l1_mmap(u32 *ttb, u32 vaddr, u32 paddr)
{
    ttb[vaddr >> 20] = (paddr & 0xfff00000) | (0<<18) | (0<<5) | 2;
}

void ttb_l2_mmap(u32 *ttb, u32 *ttb_l2, u32 vaddr, u32 paddr)
{
    ttb[vaddr >> 20] = ((u32)ttb_l2 & 0xfffffc00) | (0<<5) | 1;
    ttb_l2[(vaddr >> 12) & 0xff] = (paddr & 0xfffff000) | (0<<5) | 2;
}

void mmu_enable(u32 ttb, u32 domain)
{
    asm __volatile__(
        "mcr p15, 0, %0, c3, c0, 0\n\t" //domain
        "mcr p15, 0, %1, c2, c0, 0\n\t" //ttbr0
        "mrc p15, 0, r0, c1, c0, 0\n\t" //sctlr.M
        "orr r0, r0, #1\n\t"
        "mcr p15, 0, r0, c1, c0, 0\n\t"
        :
        : "r" (domain), "r"(ttb) 
        : "r0"
    );
}
