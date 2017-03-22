
#define udelay      ((void (*)(unsigned int))0x43e26480)

int main(void)
{
    buzzer_init();

    while(1)
    {
        buzzer_on();
        delay(1000000000);
        buzzer_off();
        delay(1000000000);
    }
    return 0;
}
