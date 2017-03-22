#include <config.h>
#include <pwm.h>

void pwm_timer4_irq_init(u32 s)
{
    //PCLK /(249+1) = 400000HZ
    set_nbit(TCFG0, 8, 8, 249); 
    //400000/4 = 100000HZ;
    set_nbit(TCFG1, 16, 4, 2);  //(100KHZ -> 10us) (1GHZ -> 1ns) (1MHZ -> 1us) (1KHZ -> 1ms)
    
    //使能中断timer4
    set_one(TINT_CSTAT, 4);

    set_val(TCNTB4, s * 100000);
    set_one(TCON, 21);          //Updates TCNTB4

    set_nbit(TCON, 20, 3, 5);   //auto-reload 和 Starts Timer 4
}

void do_pwm_timer4(void)
{
    printf("pwm timer4 handler\n");
    set_one(TINT_CSTAT, 9);
}
