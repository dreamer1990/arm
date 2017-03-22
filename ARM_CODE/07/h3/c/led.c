#include <type.h>
#include <gpio.h>

void led_init(void)
{
    //配置成输出; 
    *(v32 *)GPM4CON &= ~0xffff;
    *(v32 *)GPM4CON |= 0x1111;
}

void led_allon(void)
{
    //输出低电平全亮;
    *(v32 *)GPM4DAT &= ~0xf;
}

void led_alloff(void)
{
    //输出高电平全灭;
    *(v32 *)GPM4DAT |= 0xf;
}

void led_on(v32 val)
{
    //输出低电平亮;
    *(v32 *)GPM4DAT &= ~(1<<val);
 }

void led_off(v32 val)
{
    //输出低电平灭;
    *(v32 *)GPM4DAT |= (1<<val);
}

v32 led_get(void)
{
    //获取当前led的状态;
    return (*(v32 *)GPM4DAT) & 0xf;
}

void led_set(v32 val)
{
    //设置当前led的状态;
    *(v32 *)GPM4DAT = val & 0xf;
}
    
