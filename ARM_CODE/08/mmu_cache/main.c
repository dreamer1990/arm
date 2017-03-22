#include <config.h>
#include <string.h>

extern unsigned int __bss_start;
extern unsigned int __bss_end;

u32 *ttb  = (void *)0x70000000; //app1
int main(void)
{
    u32 i, j;
    printf("main start\n");
    memset(&__bss_start, 0, (u32)&__bss_end - (u32)&__bss_start);

    memset(ttb, 0, 4096 * 4);
    ttb_init(ttb);
    enable_cache();
    mmu_enable(ttb, 0xffffffff);

    for(i = 0; i < 10000; i++)
        for(j = 0; j < 10000; j++)
            ;

    printf("main end\n");
    return 0;
}
