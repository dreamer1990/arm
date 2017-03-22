
#include "res.h"
#include "basedevice.h"

int (*printf)(const char *fmt , ...) = (void *)0x43e11a2c ;
void (*udelay)(unsigned int usec) = (void *)0x43e26480;
void vector_copy(void);

void do_Reset(void);
void do_Undef(void);
void do_Svc(void);
void do_PrefetchAbt(void);
void do_DataAbt(void);
void do_Irq(void);
void do_Fiq(void);


int _start(void)
{
	*(U32 *)0x62000000 = (U32)do_Reset ; 
	*(U32 *)0x62000004 = (U32)do_Undef;
	*(U32 *)0x62000008 = (U32)do_Svc;
	*(U32 *)0x6200000C = (U32)do_PrefetchAbt;
	*(U32 *)0x62000010 = (U32)do_DataAbt;
	*(U32 *)0x62000014 = (U32)do_Irq;
	*(U32 *)0x62000018 = (U32)do_Fiq;

	enable_mmu();

	vector_copy();

#if 1
	__asm__ __volatile__ (
	".word  0x77777777   \n"   //undefine  exception
	".word  0x77777778   \n"   //undefine  exception
	"svc	#33          \n"
	);
#endif



	return 0 ; 
}

void do_Reset(void)
{
	printf("this is reset ... \n");
}
void do_Undef(void)
{
	printf("this is do_Undef... \n");
}
void do_Svc(void)
{
	printf("this is do_Svc ... \n");
}
void do_PrefetchAbt(void)
{
	printf("this is do_PrefetchAbt... \n");
}
void do_DataAbt(void)
{
	printf("this is do_DataAbt... \n");
}
void do_Irq(void)
{
	printf("this is do_Irq... \n");
}
void do_Fiq(void)
{
	printf("this is do_Fiq... \n");
}

void vector_copy(void)
{
	extern void start(void);
	extern void end(void);

	unsigned int offset = (unsigned int)end - (unsigned int)start;

	//printf("offset:%d \n" , offset);

	memcpy((char *)0x5FFF0000 , (char *)start , offset+200);
}
