#include <string.h>
#include <config.h>

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

    u32 cpsr;
    asm __volatile__(
        "mrs r0, cpsr\n\t"
        "bic r0, r0, #0x1f\n\t"
        "orr r0, r0, #0x10\n\t"     //进入user模式;
        "msr cpsr, r0\n\t"
        "mrs %0, cpsr\n\t"
//        "mov sp, #0x77000000\n\t"
        : "=r" (cpsr)
        :
        : "r0"
    );

    printf("cpsr : %x\n", cpsr);

    //软中断异常;
    /*
    asm __volatile__(
        //"swi #5\n\t"
        "svc #5\n\t"
    );
    */

    asm __volatile__(
        ".word  0xffffffff"
    );

    /*
    asm __volatile__(
        ".short 0xffff"
    );
    */

    u32 val;
    asm __volatile__(
        "mrs %0, cpsr\n\t"
        : "=r" (val)
    );

    printf("cpsr : %x\n", val);

    printf("main end\n");
    return 0;
}
