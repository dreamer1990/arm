#include <config.h>
#include <string.h>

extern unsigned int __bss_start;
extern unsigned int __bss_end;

u32 *ttb = (void *)0x70000000;          //一级页表
u32 *ttb_l2 = (void *)0x70100000;       //二级页表
int main(void)
{
    u32 i;
    printf("main start\n");
    memset(&__bss_start, 0, (u32)&__bss_end - (u32)&__bss_start);

    //0x4004c4 <-> 0x504004c4
    //0x4      <-> 0x504M
    //虚拟地址     物理地址;
    u32 *p = (void *)0x504004c4;    //指向物理地址 存数据
    *p = 0x11223344;

    ttb_init(ttb);
    ttb_l1_mmap(ttb, 0x4004c4, 0x504004c4);
    mmu_enable(ttb, 0xffffffff);

    p = (void *)0x4004c4;           //指向虚拟地址 读数据
    printf("*p = %p\n", *p);

    p = (void *)0x400000;
    for(i = 0; i < 1025; i++)
    {
        p[i] = i;
        printf("p[%d] = %d\n", i, p[i]);
    }

    printf("main end\n");
    return 0;
}
