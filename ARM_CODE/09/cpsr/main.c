#include <config.h>
#include <string.h>

extern unsigned int __bss_start;
extern unsigned int __bss_end;

u32 *ttb  = (void *)0x70000000; //app1
int main(void)
{
    printf("main start\n");
    memset(&__bss_start, 0, (u32)&__bss_end - (u32)&__bss_start);

    u32 cpsr;
    asm __volatile__(
        "mrs %0, cpsr"
        : "=r" (cpsr)
    );

    printf("cpsr : %x\n", cpsr);

    u32 val;
    asm __volatile__(
        "mrs r0, cpsr\n\t"
        "bic r0, r0, #0x1f\n\t"
        "orr r0, r0, #0x10\n\t"     //svc切换到user
        "msr cpsr, r0\n\t"
        "mrs %0, cpsr\n\t"
        /*
        "mrs r0, cpsr\n\t"
        "bic r0, r0, #0x1f\n\t"
        "orr r0, r0, #0x13\n\t"     //user切换到svc 失败;
        "msr cpsr, r0\n\t"
        */
        : "=r" (val)
        :
        : "r0"
    );

    asm __volatile__(
        "mov sp, #0x77000000"       //给user模式下的sp赋值;
    );
    
    printf("val : %x\n", val);

    printf("main end\n");
    return 0;
}
