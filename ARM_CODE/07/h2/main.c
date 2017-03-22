
#define udelay      ((void (*)(unsigned int))0x43e26480)

int main(void)
{
    //buzzer_init();
    led_init();
    key_init();

    led_alloff();
    int i = 0;
    int val = key_get();            //当前按键状态;
    while(1)
    {   
        if(val == key_get())        //没有变化;
            continue;
           
        //有发生变化:
        val = key_get();
        led_set(led_get() ^ ~val);

        udelay(10000);
    }

    return 0;
}
