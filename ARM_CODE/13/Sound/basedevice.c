
#include "basedevice.h"

void Led_On(void)
{
	//pull down
	GPM4DAT &= ~0xF ; 
}

void Led_Off(void)
{
	//pull up
	GPM4DAT |= 0xF ; 
}

void Configure_led(void)
{
	//1.配置为输出
	//clear
	GPM4CON  &= ~0xFFFF ; 
	//set as output
	GPM4CON  |= 0x1111 ; 
	
	//2.配置默认状态
	Led_Off();
}

void Buzzer_On(void)
{
	//up
	GPD0DAT |= 0x1 ; 
}

void Buzzer_Off(void)
{
	GPD0DAT &= ~0x1 ; 
}

void Configure_Buzzer(void)
{
	//1.配置为输出
	GPD0CON  &= ~0xF ; 
	GPD0CON  |= 0x1 ; 

	//2.配置默认状态
	Buzzer_Off();
}





