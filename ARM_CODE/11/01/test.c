
#include "res.h"
#include "basedevice.h"

int (*printf)(const char *fmt , ...) = (void *)0x43e11a2c ;
void (*udelay)(unsigned int usec) = (void *)0x43e26480;

int c ;
int Barray[20] = {0};

int _start(void)
{
	int a = 100 ; 
	int b = 3 ; 
	int Array[10] = {0};

	printf("a:%d b:%d \n" , a , b);
	printf("c:%d \n" , c);

	printf("a:%d \n" , a/b);
	printf("a:%d \n" , a%b);

	Configure_Buzzer();
	Configure_led();

	printf("led on ... \n");
	Buzzer_On();
	Led_On();

	udelay(1000000);
	//printf("hello world \n");

	Buzzer_Off();	
	Led_Off();

	return 0 ; 
}
