#include <gpio.h>
#include <config.h>

void led_init(void)
{
    //配置成输出; 
    set_nbit(GPM4CON, 0, 16, 0x1111);
}

void led_allon(void)
{
    //输出低电平全亮;
    set_nbit(GPM4DAT, 0, 4, 0x0);
}

void led_alloff(void)
{
    //输出高电平全灭;
    set_nbit(GPM4DAT, 0, 4, 0xf);
}

void led_on(v32 val)
{
    //输出低电平亮;
    set_zero(GPM4DAT, val);
 }

void led_off(v32 val)
{
    //输出低电平灭;
    set_one(GPM4DAT, val);
}

v32 led_get(void)
{
    //获取当前led的状态;
    return get_nbit(GPM4DAT, 0, 4);
}

void led_set(v32 val)
{
    //设置当前led的状态;
    set_nbit(GPM4DAT, 0, 4, val);
}
    
