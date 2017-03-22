#include <string.h>
#include <config.h>
#include <gic.h>

extern unsigned int __bss_start;
extern unsigned int __bss_end;

extern void vector_start();
extern void vector_end();

u32 *ttb  = (void *)0x70000000; //app1
int main(void)
{
    printf("main start\n");
    memset(&__bss_start, 0, (u32)&__bss_end - (u32)&__bss_start);
    
    u32 virt = 0xffff0000;
    u32 phys = 0x7fff0000;

    //使能高异常向量表地址: 0xffff0000;
    asm __volatile__(
        "mrc p15, 0, r0, c1, c0, 0\n\t"
        "orr r0, r0, #(1<<13)\n\t"
        "mcr p15, 0, r0, c1, c0, 0\n\t"
        ::: "r0"
    );

    ttb_init(ttb);
    ttb_l1_mmap(ttb, virt, phys);
    mmu_enable(ttb, 0xffffffff);

    //把异常向量表拷贝到0xffff0000
    memcpy((void *)virt, vector_start, vector_end - vector_start);  
    
    //cpsr.I 使能中断;
    asm __volatile__(
        "cpsie i\n\t"
    );
    
    enable_cpu(255);
    enable_irq(75, 75); 

    wdt_irq_init(5);

    printf("main end\n");
    return 0;
}

