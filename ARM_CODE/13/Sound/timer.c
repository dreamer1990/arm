

#include "timer.h"


void enable_PWM(void)
{


	//1.配置第一分频
	TCFG0 &= ~0xFF ; 
	TCFG0 |= 99 ;    //100M/(99+1)  ==> 1M
	
	//2.配置第二分频
	TCFG1 &= ~0xF ;
	
	//3.auto-reload
	TCON |= 1 << 3 ;

	//4.TCNTB  TCMPB
	TCNTB0 = 1000000 -1; 
	TCMPB0 = 800000 - 1 ; 

	//5.manual update
	TCON |= 1 << 1 ; 
	
	//6.clear manual update
	TCON &= ~(1 << 1) ; 

	//7.invert-on
	TCON |= 1 << 2 ;

	//start timer
	TCON |= 1 ; 

	//set ip as PWM_TOUT0
	GPD0CON &= ~0xF ; 
	GPD0CON |= 0x2 ; 


}

void enable_TIMER(void)
{
	
	enable_internal_irq(69);

	//enable_PWM();
	//1.配置第一分频
	TCFG0 &= ~0xFF ; 
	TCFG0 |= 99 ;    //100M/(99+1)  ==> 1M
	
	//2.配置第二分频
	TCFG1 &= ~0xF ;
	
	//3.auto-reload
	TCON |= 1 << 3 ;

	//4.TCNTB 
	TCNTB0 = 100 -1; 

	//5.manual update
	TCON |= 1 << 1 ; 
	
	//6.clear manual update
	TCON &= ~(1 << 1) ; 

	//7.开启定时器中断
	TINT_CSTAT |= 1  ; 
}

void start_timer(void)
{
	//start timer
	TCON |= 1 ; 
}

void stop_timer(void)
{
	TCON &= ~0x1 ; 
}

void enable_ADC_IRQ(void)
{

	//enable internal irq
	enable_internal_irq(42);
	//enable combiner irq   G 10  index 3
	IESR2 |= 1 << 19 ; 
	

	//1.system register  =>  general ADC
	#define  ADC_CFG   *(U32 *)0x10010118
	ADC_CFG &= ~(1 << 16) ; 

	//2.set Data output as 12bits
	ADCCON |= 1 << 16 ; 

	//3.enable ADC converter prescale
	ADCCON |= 1 << 14 ; 
	ADCCON &= ~(0xFF<<6) ; 
	ADCCON |= 19 << 6 ;    //convert clock 5M  dataoutput 1MSPS

	//4.clear standby mode
	ADCCON &= ~(1 << 2) ;

	//5.select channels
	ADCMUX = 0 ; 

	//6.start by enable
	ADCCON |=  1 ; 

}

