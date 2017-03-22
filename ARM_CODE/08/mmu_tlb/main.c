#include <config.h>
#include <string.h>

extern unsigned int __bss_start;
extern unsigned int __bss_end;

u32 *ttb  = (void *)0x70000000; //app1
u32 *ttb2 = (void *)0x70004000; //app2
int main(void)
{
    u32 i;
    printf("main start\n");
    memset(&__bss_start, 0, (u32)&__bss_end - (u32)&__bss_start);

    //0x4004c4 <-> 0x504004c4
    //0x4004c4 <-> 0x604004c4
    //虚拟地址     物理地址;
    u32 *p = (void *)0x504004c4;    //指向物理地址 存数据
    *p = 0x11223344;
    p = (void *)0x604004c4;
    *p = 0x55667788;

    memset(ttb, 0, 4096 * 4);
    memset(ttb2, 0, 4096 * 4);
    ttb_init(ttb);
    ttb_init(ttb2);
    ttb_l1_mmap(ttb, 0x4004c4, 0x504004c4);
    ttb_l1_mmap(ttb2, 0x4004c4, 0x604004c4);
    mmu_enable(ttb2, 0xffffffff);

    p = (void *)0x4004c4;           //指向虚拟地址 读数据
    while(1)
    {
    //#if 0
        clean_tlb();
        change_ttb(ttb);
        printf("app1: *p = %p\n", *p);
        udelay(1000000);
    //#else
        clean_tlb();
        change_ttb(ttb2);
        printf("app2: *p = %p\n", *p);
        udelay(1000000);
    //#endif
    }

    printf("main end\n");
    return 0;
}
