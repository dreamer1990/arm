
#include "res.h"

void Init_Serial(void)
{
	#define GPA0CON    *(U32 *)0x11400000
	//1.设备IP为串口模式   GPA0_0  GPA0_1
	GPA0CON &= ~0xFF ;
	GPA0CON |= 0x22  ;

	//2.分频  固定100M

	//3.配置8N1
	ULCONn = 0x3 ; 

	//4.轮询模式  polling mode
	UCONn = 0x5 ; 

	//5.配置baud rate
	// 100M/(115200*16)-1  ==> 53.2534  整数部分 53    小数部分 0.2534*16=>4
	UBRDIVn = 53 ; 
	UFRACVALn = 4 ;
}

void Serial_Operation(void)
{

	myprintf("hello world %d %o %x %b %c %s \n" , 255,255,255,255 ,  'C' , "hello");

	myprintf("*********************************************\n");
	myprintf("**      Welcome  uplooking ...             **\n");
	myprintf("**             0326                        **\n");
	myprintf("**            kitty                        **\n");
	myprintf("*********************************************\n");

	char Buffer[100] ; 
	char *Command[] = {
	"led_on",
	"led_off",
	"buzzer_on",
	"buzzer_off",
	"exit",
	};
	
	Configure_Buzzer();
	Configure_led();
	//......

	int i ; 
	while(1)
	{
		myprintf("[root@cjy ]# ");
		gets(Buffer);
		for(i = 0 ; i < 5 ; i++)
		{
			if(strcmp(Buffer , Command[i]) == 0)
				break;
		}
		if(*Buffer == '\0')
			continue ; 
		
		if(i == 5)
		{
			myprintf("Command Not Found!\n");
			continue ; 
		}
		
		if(i == 4)
			break;

		switch(i)
		{
		case 0: Led_On();  break;
		case 1: Led_Off(); break;
		case 2: Buzzer_On(); break;
		case 3: Buzzer_Off(); break;
		}

		//myprintf("haha:  %s  \n" , Buffer);
	}

}

char getchar(void)
{
	char ch ; 
	while(1)
	{
		if(!(UTRSTATn & 0x1))
			continue ; 
		ch = URXHn ; 
		putchar(ch);
		if(ch == '\r')
			putchar('\n');
		break;
	}
	return ch ; 
}
void gets(char *buffer)
{
	char ch ; 
	while(1)
	{
		ch = getchar();
		if(ch == '\r')
			break;
		*buffer++ = ch ; 
	}
	*buffer = '\0' ; 
}

void putchar(char ch)
{
	while(1)
	{
		if(!(UTRSTATn & (1 << 2)))
			continue ; 
		UTXHn = ch ; 
		if(ch== '\n')
			putchar('\r');
		break;
	}
}

void print_num(int num , int base)
{
	if(num == 0)
		return ; 
	print_num(num/base , base);
	putchar("0123456789ABCDEF"[num%base]);
}

void puts(const char *str)
{
	while(*str)
	{
		putchar(*str++);
	}
}

int myprintf(const char *fmt , ...)
{
	int *Addr = &fmt ; 
	//通过栈的方式去获取可变参
#if 0
	printf("%d \n" , *(Addr+1));
	printf("%c \n" , *(Addr+2));
	printf("%s \n" , *(Addr+3));
#endif
	Addr++ ; 
	while(*fmt)
	{
		if(*fmt != '%')
		{
			putchar(*fmt);
			fmt++ ; 
			continue ; 
		}
		//保证到这里就找到%
		fmt++ ;
		switch(*fmt)
		{
		case 'd' :  print_num(*Addr++ , 10);  break;
		case 'o' :  print_num(*Addr++ , 8) ;  break;
		case 'x' :  print_num(*Addr++ , 16);  break;
		case 'c' :  putchar(*Addr++);         break;
		case 's' :  puts((char *)(*Addr++));  break;
		case 'b' :  print_num(*Addr++ , 2);   break;
		}
		fmt++ ; 
	}
}

