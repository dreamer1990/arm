#include <config.h>
#include <string.h>

extern unsigned int __bss_start;
extern unsigned int __bss_end;

u32 *ttb  = (void *)0x70000000; //app1
int main(void)
{
    u32 i, j;
    u32 *p;
    printf("main start\n");
    memset(&__bss_start, 0, (u32)&__bss_end - (u32)&__bss_start);

    p = (void *)0x7fff0000;
    *p = 0x11223344;

    memset(ttb, 0, 4096 * 4);
    ttb_init(ttb);
    ttb_l1_mmap(ttb, 0xffff0000, 0x7fff0000);
    mmu_enable(ttb, 0xffffffff);

    p = (void *)0xffff0000;     //重复映射; 0xffff0000 虚拟地址; 0x7fff0000 物理地址;
    printf("*p = %p\n", *p);
    p = (void *)0x7fff0000;     //平板映射; 0x7fff0000 虚拟地址; 0x7fff0000 物理地址;
    printf("*p = %p\n", *p);

    printf("main end\n");
    return 0;
}
