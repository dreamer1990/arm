#include <config.h>
#include <string.h>

extern unsigned int __bss_start;
extern unsigned int __bss_end;

int main(void)
{
    memset(&__bss_start, 0, (u32)&__bss_end - (u32)&__bss_start);

    key_init();
    adc_init();
    adc_start();
    while((key_get() & 1))
    {
        if(adc_end_flag())
        {
            printf("adc_data: %d\n", adc_data());
            udelay(10000);
            adc_start();
        }
    }
    

    return 0;
}
