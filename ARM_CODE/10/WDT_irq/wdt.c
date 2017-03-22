#include <config.h>
#include <pmu.h>
#include <wdt.h>

void wdt_reset(int s)
{
    set_zero(AUTOMATIC_WDT_RESET_DISABLE, 20);
    set_zero(MASK_WDT_RESET_REQUEST, 20);

    set_val(WTCNT, s * 3052);
    set_val(WTCON, (255<<8)|(1<<5)|(3<<3)|1);
}

void wdt_irq_init(int s)
{
    set_val(WTDAT, s * 3052);   //以后的填充时间;
    set_val(WTCNT, s * 3052);   //第一次时间;
    set_val(WTCON, (255<<8)|(1<<5)|(3<<3)|(1<<2));
}

void wdt_feed(int s)
{
    set_val(WTCNT, s * 3052);
}

void do_wdt(void)
{
    printf("wdt irq handler\n");
    set_val(WTCLRINT, 0);
}

