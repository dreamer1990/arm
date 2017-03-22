#include <config.h>
#include <string.h>

extern unsigned int __bss_start;
extern unsigned int __bss_end;

int main(void)
{
    memset(&__bss_start, 0, (u32)&__bss_end - (u32)&__bss_start);

    u32 main_id;
    asm __volatile__(
        "mrc p15, 0, %0, c0, c0, 0\n\t"
        : "=r" (main_id)
    );
    printf("main id: %p\n", main_id);

    u32 sctlr;
    asm __volatile__(
        "mrc p15, 0, %0, c1, c0, 0\n\t"
        : "=r" (sctlr)
    );

    printf("sctlr : %p\n", sctlr);

    return 0;
}
