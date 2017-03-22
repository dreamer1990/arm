#include <gpio.h>
#include <config.h>

void key_init(void)
{
    set_nbit(GPX3CON, 8, 16, 0x0);
}

unsigned int key_get(void)
{
    return  get_nbit(GPX3DAT, 2, 4);
}
