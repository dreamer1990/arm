
#include "res.h"
#include "irq.h"
#include "basedevice.h"
#include "timer.h"

int (*printf)(const char *fmt , ...) = (void *)0x43e11a2c ;
void (*udelay)(unsigned int usec) = (void *)0x43e26480;

void do_Reset(void);
void do_Undef(void);
void do_Svc(void);
void do_PrefetchAbt(void);
void do_DataAbt(void);
void do_Irq(void);
void do_Fiq(void);
char Buffer[32] = {0};


int _start(void)
{
	*(U32 *)0x62000000 = (U32)do_Reset ; 
	*(U32 *)0x62000004 = (U32)do_Undef;
	*(U32 *)0x62000008 = (U32)do_Svc;
	*(U32 *)0x6200000C = (U32)do_PrefetchAbt;
	*(U32 *)0x62000010 = (U32)do_DataAbt;
	*(U32 *)0x62000014 = (U32)do_Irq;
	*(U32 *)0x62000018 = (U32)do_Fiq;
	//开启mmu
	enable_mmu();
	//拷中断向量表
	vector_copy();
	//清掉 cpsr 的中断掩码位
	enable_cpsr_I();

	//enable_internal_irq(84);

	//1.产生一个中断  14外部中断 确定触发方式
	enable_external_irq(14 , TRIGGER_FALLING_EDGE);
	//中断确定是连续触发类型
	//2.配置GPIO  设置为I2C模式   GPD1_2  GPD1_3
	GPD1CON &= ~(0xFF << 8);
	GPD1CON |= 0x22 << 8 ; 
	
	//3.配置时序
	I2CCONn &= ~0xFF ; 
	I2CCONn |= (1 << 6) | 1 ; //大概200K
	
	//4.设置主机接收
	I2CSTATn &= ~(0x3 << 6) ; 
	I2CSTATn |= 1 << 7 ; 

	//enable irq
	I2CCONn |= 1 << 5 ; 
	
	//enable ACK
	I2CCONn  |= 1 << 7;


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

int Wait_Ack(void)
{
	int i ; 
	for(i = 0 ; i < 0xFFF ; i++)
	{
		if(!(I2CSTATn & 1))
		{
			return 1 ;
		}
	}
	return 0 ; 
}

int Wait_Interrupt(void)
{
	int i ; 
	for(i = 0 ; i < 0xFFFF ; i++)
	{
		if(I2CCONn & (1 << 4))
		{
			return 1 ;
		}
	}
	return 0 ; 
}

int Clear_Interrupt(void)
{
	I2CCONn &= ~(1 << 4) ; 
}


void Read_I2c_Data(int SlaveAddr , char *Buffer , int len)
{
	int ret ; 
	//1.设置主机接收
	I2CSTATn &= ~(0x3 << 6) ; 
	I2CSTATn |= 1 << 7 ; 

	//2.写从机地址
	I2CDSn = 0x70 | 0x1; 

	//3.发送开始位
	I2CSTATn = 0xB0 ; 

	//4. 判断ACK有没有接收到
	
	Clear_Interrupt();
	ret = Wait_Interrupt();
	if(ret == 0)
	{
	//	printf("Wait interruptible fail \n");
		goto Err ; 
	}

	ret = Wait_Ack();
	if(ret == 0)
	{
	//	printf("Wait Ack Error \n");
		goto Err ; 
	}
	

#if 1
	//接收到ACK
	int i ; 
	for(i = 0 ; i < len ; i++)
	{
		Clear_Interrupt();
		ret = Wait_Interrupt();
		if(ret == 0)
		{
	//		printf("Wait interruptible fail \n");
			goto Err ; 
		}
		Buffer[i] = I2CDSn ; 
	}
#endif

Err:
	I2CSTATn = 0x90 ; 
	
	Clear_Interrupt();
	
	//udelay(100);
}


void do_Irq(void)
{
	unsigned int val ; 
	val = ICCIAR_CPU0 ; 
#if 0
	char ch ; 
	if(UINTPn & 0x1)
	{
		ch = URXHn ;    //
		GPM4DAT = UINTPn & 0xF ; 
		printf("haha ... ch:%c %p\n" , ch , UINTPn&0xF);
		UINTPn |= 0xF ; 
	}

	if(UINTPn & (1 << 2))
	{
		UTXHn = ch ; 
		UINTPn |= 1 << 2 ; 
	}
#endif

#if 0
	if(UINTPn & (1 << 2))
	{
		printf("hehe ... \n");
		ch = URXHn ;    //
		UINTPn |= 1 << 2 ; 
	}
#endif


#if 0
	if(UINTPn & (0x1 << 2))
	{
		printf("haha2 ... \n");
		UTXHn = ch ; 
		UINTSPn |= 1 << 2 ; 
	}
#endif


	//printf("this is do_Irq... val:%d id:%d \n" , val , val&0x3FF);
	
	int i ; 
	if(EXT_INT41_PEND & (1 << 6))
	{
		//4.开始配置i2c的主体逻辑  读取i2c的数据
		Read_I2c_Data(0x11 , Buffer ,32);
		printf("num:%d ********\n" , Buffer[2]&0xF );
		for(i = 0 ; i < Buffer[2]&0xF ; i++)
		{
			printf("i:%3d x:%5d y:%5d \n" ,i , ((Buffer[3+i*6]&0xF)<<8)|Buffer[4+i*6] , ((Buffer[5+i*6]&0xF)<<8)|Buffer[6+i*6] );
		}
	 	//
		EXT_INT41_PEND = EXT_INT41_PEND ; 
	}

	if(EXT_INT43_PEND & (1 << 2))
	{
		printf("frist key press ... \n");
		EXT_INT43_PEND = EXT_INT43_PEND ; 
	}
	if(EXT_INT43_PEND & (1 << 3))
	{
		printf("second key press ... \n");
		EXT_INT43_PEND = EXT_INT43_PEND ; 
	}
	if(EXT_INT43_PEND & (1 << 4))
	{
		printf("third key press ... \n");
		EXT_INT43_PEND = EXT_INT43_PEND ; 
	}
	if(EXT_INT43_PEND & (1 << 5))
	{
		printf("fourth key press ... \n");
		EXT_INT43_PEND = EXT_INT43_PEND ; 
	}

	if(TINT_CSTAT & (1 << 5))
	{
		printf("tick ... \n");
		TINT_CSTAT |= 1 << 5 ;
	}
	
	//adc
	if(ISTR2 & (1 << 19))
	{
		if(ADCCON & (1 << 15))
		{
		printf("ADCDAT:%#5x \n" , ADCDAT&0xFFF);
		}
		ADCCON |= 1 ; 
		//清中断
		CLRINTADC = 0 ; 
	}

	//处理完
	ICCEOIR_CPU0 = val ; 
}
void do_Fiq(void)
{
	printf("this is do_Fiq... \n");
}
