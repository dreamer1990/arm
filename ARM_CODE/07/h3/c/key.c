#include <type.h>
#include <gpio.h>

void key_init(void)
{
    *(v32 *)GPX3CON &= ~0xffff00;
}

unsigned int key_get(void)
{
    return  (*(v32 *)GPX3DAT >> 2) & 0xf;
}
