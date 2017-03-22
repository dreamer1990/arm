
#define udelay      ((void (*)(unsigned int))0x43e26480)

int main(void)
{
    buzzer_init();

    int val = 1000;
    int i;
    while(1)
    {
        for(i = 0; i < 1000; i++)
        {
            buzzer_on();
            udelay(val);
            buzzer_off();
            udelay(val);
        }

        val += 1000;
    }
    return 0;
}
