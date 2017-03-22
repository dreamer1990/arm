#include <config.h>
#include <pmu.h>

void do_reset(void)
{
    set_one(SWRESET, 0);
}
