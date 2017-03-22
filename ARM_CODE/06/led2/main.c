
//#define udelay      ((void (*)(unsigned int))0x43e26480)

int main(void)
{
    led_init();

    while(1)
    {
        led_allon();
        delay(1000000000U);
        //udelay(1000000);
        led_alloff();
        delay(1000000000U);
        //udelay(1000000);
    }

    return 0;
}
