
#define udelay      ((void (*)(unsigned int))0x43e26480)

int main(void)
{
    buzzer_init();
    key_init();

    while((key_get() & 1<<1))
    {
        if(!(key_get() & 1))
            buzzer_on();
        else
            buzzer_off();
    }
    return 0;
}
