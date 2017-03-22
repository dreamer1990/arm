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


void wdt_feed(int s)
{
    set_val(WTCNT, s * 3052);
}


