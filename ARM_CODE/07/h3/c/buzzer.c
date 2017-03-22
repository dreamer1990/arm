#include <type.h>
#include <gpio.h>

void buzzer_init(void)
{
    *(v32 *)GPD0CON &= ~0xf;
    *(v32 *)GPD0CON |= 1;
}

void buzzer_on(void)
{
    *(v32 *)GPD0DAT |= 1;
}

void buzzer_off(void)
{
    *(v32 *)GPD0DAT &= ~1;
}   
