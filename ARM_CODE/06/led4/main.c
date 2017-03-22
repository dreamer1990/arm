
#define udelay      ((void (*)(unsigned int))0x43e26480)

int main(void)
{
    led_init();
    led_alloff();
    int val = 0;
    int flag = 0;
    while(1)
    {
        led_on(val);
        udelay(100000);
        led_off(val);
        //udelay(100000);

        if(flag == 0)
            val ++;
        else 
            val --;

        if(val == 4)
            flag = 1;
        if(val == -1)
            flag = 0;
            
        //    val = 0;
    }

    return 0;
}
