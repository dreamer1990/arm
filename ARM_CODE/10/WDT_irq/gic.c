#include <config.h>
#include <gic.h>

void enable_cpu(u32 pmask)
{
    set_one(ICCICR_CPU(0), 0);              //cpu0使能中断处理;
    set_nbit(ICCPMR_CPU(0), 0, 8, pmask);   //设置cpu0的中断屏蔽级别;
}

void enable_irq(u32 num, u32 p)
{
    set_one(ICDDCR, 0);                     //使能仲裁器;
    set_one(ICDISER_CPU(0, num/32), num%32);//使能中断;
    set_nbit(ICDIPR_CPU(0, num/4), (num%4)*8, 8, p);    //设置中断的优先级别;
    set_nbit(ICDIPTR_CPU(0, num/4), (num%4)*8, 8, 1);   //指定目标cpu为cpu0;
}

void send_sgi(u32 num)
{
    set_val(ICDSGIR, (1<<16)|num);
}

void do_irq(void)
{
    u32 tmp = get_nbit(ICCIAR_CPU(0), 0, 13);
    printf("CPUID: %d IRQID: %d\n", (tmp>>10) & 0x7, tmp & 0x3ff);
    set_nbit(ICCEOIR_CPU(0), 0, 13, tmp);

    switch(tmp & 0x3ff)
    {
        case 75:
            do_wdt();
            break;
    }
}
