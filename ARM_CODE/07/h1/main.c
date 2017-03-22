
#define udelay      ((void (*)(unsigned int))0x43e26480)

int main(void)
{
    //buzzer_init();
    led_init();
    key_init();

    int i;
    int val = 0;
    while(1)
    {   
        led_set(key_get());
    /*
        val = 0;
        for(i = 0; i < 4; i++)
        {
            if(!(key_get() & (1<<i)))
            {
                led_on(i);
                val ++;
            }
            else
                led_off(i);
        }
        if(val >= 2)
            break;
    */
    }

    return 0;
}
