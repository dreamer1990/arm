
#define udelay      ((void (*)(unsigned int))0x43e26480)

int main(void)
{
    //buzzer_init();
    led_init();
    key_init();

    led_alloff();
    int i = 0;
    while(1)
    {   
        udelay(10000);

        if(!(key_get() & (1<<i)))
            led_set(led_get() ^ (1<<i)); 

        //按下状态; 等待抬起;
        while(!(key_get() & (1<<i)))    
            ;

        //抬起状态; 等待按下;
        while(key_get() & (1<<i))       
            ;

    }

    return 0;
}
