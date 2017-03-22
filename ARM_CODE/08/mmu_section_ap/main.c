#include <config.h>
#include <string.h>

extern unsigned int __bss_start;
extern unsigned int __bss_end;

u32 *ttb = (void *)0x70000000;  //16K地址对齐; 
int main(void)
{
    printf("main start\n");
    memset(&__bss_start, 0, (u32)&__bss_end - (u32)&__bss_start);

    //0x4004c4 <-> 0x504004c4
    //0x4      <-> 0x504M
    //虚拟地址     物理地址;
    u32 *p = (void *)0x504004c4;    //指向物理地址 存数据
    *p = 0x11223344;

    //u32 ttb[4096];      //16K     不能保证16K对齐; 
    memset(ttb, 0, 4096 * 4);       //初始化映射表;
    //ttb[0x4] = (0x504<<20)|(0<<18)|(1<<5)|2;   //1M段映射;
    ttb[0x4] = (0x504<<20)|(0<<18)|(3<<10)|(1<<5)|2;   //1M段映射;
                                  //^ read/write
    
    //u-boot的代码本身:(运行环境) printf delay ...  0x43e00000 - xxx
    //stack 内存地址;  (p 指向栈的空间)             xxx - 0x42e00000 fd
    u32 i;
    for(i = 0x42000000; i < 0x44000000; i+=0x100000)    //平板映射; 物理地址==虚拟地址
        ttb[i >> 20] = (i & 0xfff00000) | (0<<18) | (0<<5) | 2; 

    //当前代码本身的.text .rodata .data .bss 
    ttb[0x500] = (0x500<<20)|(0<<18)|(0<<5)|2;

    //uart寄存器; printf -> uart0
    for(i = 0x10000000; i < 0x14000000; i+=0x100000)
        ttb[i >> 20] = (i & 0xfff00000) | (0<<18) | (0<<5) | 2;
    
    //映射表项的访问权限:
    //D0域访问身份改成管理者; 不用检查权限;
    //D1域访问身份改成客户;   要检查权限;
    asm __volatile__(
        "mcr p15, 0, %0, c3, c0, 0\n\t"
//        ::"r" (0xf)
        ::"r" ((1<<2)|3)
        //      ^客户 ^管理者
    );

    //写映射表基地址到ttbr0中;
    asm __volatile__(
        "mcr p15, 0, %0, c2, c0, 0\n\t"
        :: "r"(ttb)
    );

    //enable mmu
    asm __volatile__(
        "mrc p15, 0, r0, c1, c0, 0\n\t"
        "orr r0, r0, #1\n\t"
        "mcr p15, 0, r0, c1, c0, 0\n\t"
        :::"r0"
    );

    p = (void *)0x4004c4;           //指向虚拟地址 读数据
    printf("*p = %p\n", *p);
    printf("main end\n");
    return 0;
}
