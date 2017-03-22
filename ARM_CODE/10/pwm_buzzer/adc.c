#include <config.h>
#include <adc.h>

void adc_init(void)
{
    set_zero(ADC_CFG, 16);
    set_nbit(ADCMUX, 0, 4, 0x0);
    set_val(ADCCON, (1<<16)|(1<<14)|(19<<6));
}

void adc_start(void)
{
    set_one(ADCCON, 0);
}

int adc_end_flag(void)
{
    return get_bit(ADCCON, 15);
}

int adc_data(void)
{
    return get_nbit(ADCDAT, 0, 12);
}


