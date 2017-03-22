#include <config.h>
#include <string.h>

void ttb_init(u32 *ttb)
{
    u32 i;
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

void clean_tlb(void)
{
    asm __volatile__(
        "mcr p15, 0, r0, c8, c7, 0\n\t"
    );
}

void mmu_enable(u32 *ttb, u32 domain)
{
    clean_tlb();
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

void change_ttb(u32 *ttb)
{
    asm __volatile__(
        "mcr p15, 0, %0, c2, c0, 0\n\t"
        ::"r"(ttb)
    );
}

void enable_cache(void)
{
    asm __volatile__(
        "mrc p15, 0, r0, c1, c0, 0\n\t"
        "orr r0, r0, #(1<<2)\n\t"
        "orr r0, r0, #(1<<12)\n\t"
        "mcr p15, 0, r0, c1, c0, 0\n\t"
        ::: "r0"
    );
}


