
#ifndef _RES_H
#define _RES_H

#include "cpu.h"

typedef volatile unsigned int U32 ; 
typedef volatile unsigned short U16 ; 
typedef volatile unsigned char  U8 ; 

#define   NULL   0
typedef unsigned int size_t ; 
typedef unsigned long  ulong ; 
typedef unsigned int u32 ; 
typedef unsigned short u16 ; 
typedef unsigned char u8 ;

//中断触发方式

#define   TRIGGER_LOW_LEVEL    0x0
#define   TRIGGER_HIGH_LEVEL   0x1
#define   TRIGGER_FALLING_EDGE  0x2
#define   TRIGGER_RISING_EDGE   0x3
#define   TRIGGER_BOTH_EDGE     0x4

	//0x0 = Low level 
    //0x1 = High level 
    //0x2 = Triggers Falling edge 
    //0x3 = Triggers Rising edge 
    //0x4 = Triggers Both edge 

//configure led register
#define  GPM4CON    *(U32 *)0x110002E0
#define  GPM4DAT   	*(U32 *)0x110002E4
//configure buzzer register
#define  GPD0CON    *(U32 *)0x114000A0
#define  GPD0DAT    *(U32 *)0x114000A4
#define  GPD1CON    *(U32 *)0x114000C0
#define  GPD1DAT    *(U32 *)0x114000C4
//configure key  register
#define  GPX3CON    *(U32 *)0x11000C60

//string operations ; 
char * strcpy(char * dest,const char *src);
char * strncpy(char * dest,const char *src,size_t count);
char * strcat(char * dest, const char * src);
char * strncat(char *dest, const char *src, size_t count);
int strcmp(const char * cs,const char * ct);
int strncmp(const char * cs,const char * ct,size_t count);
char * strchr(const char * s, int c);
size_t strlen(const char * s);
char * strrchr(const char * s, int c);
size_t strnlen(const char * s, size_t count);
size_t strspn(const char *s, const char *accept);
char * strpbrk(const char * cs,const char * ct);
char * strtok(char * s,const char * ct);
char * strsep(char **s, const char *ct);
char *strswab(const char *s);
void * memset(void * s,int c,size_t count);
char * bcopy(const char * src, char * dest, int count);
void * memcpy(void *dest, const void *src, size_t count);
void * memmove(void * dest,const void *src,size_t count);
int memcmp(const void * cs,const void * ct,size_t count);
void * memscan(void * addr, int c, size_t size);
char * strstr(const char * s1,const char * s2);
void *memchr(const void *s, int c, size_t n);
void __div0(void);

//enable  mmu  function
void init_ttb(unsigned int *ttb);
void mmap(unsigned int *ttb , unsigned int Pa , unsigned int Va);
void enable_mmu(void);


//internal irq  register
//icc
#define      iccbase      0x10480000
#define      ICCICR_CPU0  *(U32 *)(iccbase +0x0000 )
#define      ICCPMR_CPU0  *(U32 *)(iccbase +0x0004 )
#define      ICCBPR_CPU0  *(U32 *)(iccbase +0x0008 )
#define      ICCIAR_CPU0  *(U32 *)(iccbase +0x000C )
#define      ICCEOIR_CPU0 *(U32 *)(iccbase +0x0010 )

//icd
#define      icdbase       0x10490000
#define      ICDDCR        *(U32 *)(icdbase + 0x0000 )
#define      ICDICTR       *(U32 *)(icdbase + 0x0004 )
#define      ICDISER0_CPU0 *(U32 *)(icdbase + 0x0100 )
#define      ICDISER1      *(U32 *)(icdbase + 0x0104 )
#define      ICDISER2      *(U32 *)(icdbase + 0x0108 )
#define      ICDISER3      *(U32 *)(icdbase + 0x010C )
#define      ICDISER4      *(U32 *)(icdbase + 0x0110 )
#define      ICDIPR0_CPU0  *(U32 *)(icdbase + 0x0400 )
#define      ICDIPR1_CPU0  *(U32 *)(icdbase + 0x0404 )
#define      ICDIPR2_CPU0  *(U32 *)(icdbase + 0x0408 )
#define      ICDIPR3_CPU0  *(U32 *)(icdbase + 0x040C )
#define      ICDIPR4_CPU0  *(U32 *)(icdbase + 0x0410 )
#define      ICDIPR5_CPU0  *(U32 *)(icdbase + 0x0414 )
#define      ICDIPR6_CPU0  *(U32 *)(icdbase + 0x0418 )
#define      ICDIPR7_CPU0  *(U32 *)(icdbase + 0x041C )
#define      ICDIPR8       *(U32 *)(icdbase + 0x0420 )
#define      ICDIPR9       *(U32 *)(icdbase + 0x0424 )
#define      ICDIPR10      *(U32 *)(icdbase + 0x0428 )
#define      ICDIPR11      *(U32 *)(icdbase + 0x042C )
#define      ICDIPR12      *(U32 *)(icdbase + 0x0430 )
#define      ICDIPR13      *(U32 *)(icdbase + 0x0434 )
#define      ICDIPR14      *(U32 *)(icdbase + 0x0438 )
#define      ICDIPR15      *(U32 *)(icdbase + 0x043C )
#define      ICDIPR16      *(U32 *)(icdbase + 0x0440 )
#define      ICDIPR17      *(U32 *)(icdbase + 0x0444 )
#define      ICDIPR18      *(U32 *)(icdbase + 0x0448 )
#define      ICDIPR19      *(U32 *)(icdbase + 0x044C )
#define      ICDIPR20      *(U32 *)(icdbase + 0x0450 )
#define      ICDIPR21      *(U32 *)(icdbase + 0x0454 )
#define      ICDIPR22      *(U32 *)(icdbase + 0x0458 )
#define      ICDIPR23      *(U32 *)(icdbase + 0x045C )
#define      ICDIPR24      *(U32 *)(icdbase + 0x0460 )
#define      ICDIPR25      *(U32 *)(icdbase + 0x0464 )
#define      ICDIPR26      *(U32 *)(icdbase + 0x0468 )
#define      ICDIPR27      *(U32 *)(icdbase + 0x046C )
#define      ICDIPR28      *(U32 *)(icdbase + 0x0470 )
#define      ICDIPR29      *(U32 *)(icdbase + 0x0474 )
#define      ICDIPR30      *(U32 *)(icdbase + 0x0478 )
#define      ICDIPR31      *(U32 *)(icdbase + 0x047C )
#define      ICDIPR32      *(U32 *)(icdbase + 0x0480 )
#define      ICDIPR33      *(U32 *)(icdbase + 0x0484 )
#define      ICDIPR34      *(U32 *)(icdbase + 0x0488 )
#define      ICDIPR35      *(U32 *)(icdbase + 0x048C )
#define      ICDIPR36      *(U32 *)(icdbase + 0x0490 )
#define      ICDIPR37      *(U32 *)(icdbase + 0x0494 )
#define      ICDIPR38      *(U32 *)(icdbase + 0x0498 )
#define      ICDIPR39      *(U32 *)(icdbase + 0x049C )
#define      ICDIPTR0_CPU0 *(U32 *)(icdbase + 0x0800 )
#define      ICDIPTR1_CPU0 *(U32 *)(icdbase + 0x0804 )
#define      ICDIPTR2_CPU0 *(U32 *)(icdbase + 0x0808 )
#define      ICDIPTR3_CPU0 *(U32 *)(icdbase + 0x080C )
#define      ICDIPTR4_CPU0 *(U32 *)(icdbase + 0x0810 )
#define      ICDIPTR5_CPU0 *(U32 *)(icdbase + 0x0814 )
#define      ICDIPTR6_CPU0 *(U32 *)(icdbase + 0x0818 )
#define      ICDIPTR7_CPU0 *(U32 *)(icdbase + 0x081C )
#define      ICDIPTR8      *(U32 *)(icdbase + 0x0820 )
#define      ICDIPTR9      *(U32 *)(icdbase + 0x0824 )
#define      ICDIPTR10     *(U32 *)(icdbase + 0x0828 )
#define      ICDIPTR11     *(U32 *)(icdbase + 0x082C )
#define      ICDIPTR12     *(U32 *)(icdbase + 0x0830 )
#define      ICDIPTR13     *(U32 *)(icdbase + 0x0834 )
#define      ICDIPTR14     *(U32 *)(icdbase + 0x0838 )
#define      ICDIPTR15     *(U32 *)(icdbase + 0x083C )
#define      ICDIPTR16     *(U32 *)(icdbase + 0x0840 )
#define      ICDIPTR17     *(U32 *)(icdbase + 0x0844 )
#define      ICDIPTR18     *(U32 *)(icdbase + 0x0848 )
#define      ICDIPTR19     *(U32 *)(icdbase + 0x084C )
#define      ICDIPTR20     *(U32 *)(icdbase + 0x0850 )
#define      ICDIPTR21     *(U32 *)(icdbase + 0x0854 )
#define      ICDIPTR22     *(U32 *)(icdbase + 0x0858 )
#define      ICDIPTR23     *(U32 *)(icdbase + 0x085C )
#define      ICDIPTR24     *(U32 *)(icdbase + 0x0860 )
#define      ICDIPTR25     *(U32 *)(icdbase + 0x0864 )
#define      ICDIPTR26     *(U32 *)(icdbase + 0x0868 )
#define      ICDIPTR27     *(U32 *)(icdbase + 0x086C )
#define      ICDIPTR28     *(U32 *)(icdbase + 0x0870 )
#define      ICDIPTR29     *(U32 *)(icdbase + 0x0874 )
#define      ICDIPTR30     *(U32 *)(icdbase + 0x0878 )
#define      ICDIPTR31     *(U32 *)(icdbase + 0x087C )
#define      ICDIPTR32     *(U32 *)(icdbase + 0x0880 )
#define      ICDIPTR33     *(U32 *)(icdbase + 0x0884 )
#define      ICDIPTR34     *(U32 *)(icdbase + 0x0888 )
#define      ICDIPTR35     *(U32 *)(icdbase + 0x088C )
#define      ICDIPTR36     *(U32 *)(icdbase + 0x0890 )
#define      ICDIPTR37     *(U32 *)(icdbase + 0x0894 )
#define      ICDIPTR38     *(U32 *)(icdbase + 0x0898 )
#define      ICDIPTR39     *(U32 *)(icdbase + 0x089C )
#define      ICDSGIR       *(U32 *)(icdbase + 0x0F00 )

//external irq register
#define      extbase            0x11000000
#define      EXT_INT40_CON      *(U32 *)(extbase + 0x0E00)
#define      EXT_INT41_CON      *(U32 *)(extbase + 0x0E04)
#define      EXT_INT42_CON      *(U32 *)(extbase + 0x0E08)
#define      EXT_INT43_CON      *(U32 *)(extbase + 0x0E0C)
#define      EXT_INT40_FLTCON0  *(U32 *)(extbase + 0x0E80)
#define      EXT_INT40_FLTCON1  *(U32 *)(extbase + 0x0E84)
#define      EXT_INT41_FLTCON0  *(U32 *)(extbase + 0x0E88)
#define      EXT_INT41_FLTCON1  *(U32 *)(extbase + 0x0E8C)
#define      EXT_INT42_FLTCON0  *(U32 *)(extbase + 0x0E90)
#define      EXT_INT42_FLTCON1  *(U32 *)(extbase + 0x0E94)
#define      EXT_INT43_FLTCON0  *(U32 *)(extbase + 0x0E98)
#define      EXT_INT43_FLTCON1  *(U32 *)(extbase + 0x0E9C)
#define      EXT_INT40_MASK     *(U32 *)(extbase + 0x0F00)
#define      EXT_INT41_MASK     *(U32 *)(extbase + 0x0F04)
#define      EXT_INT42_MASK     *(U32 *)(extbase + 0x0F08)
#define      EXT_INT43_MASK     *(U32 *)(extbase + 0x0F0C)
#define      EXT_INT40_PEND     *(U32 *)(extbase + 0x0F40)
#define      EXT_INT41_PEND     *(U32 *)(extbase + 0x0F44)
#define      EXT_INT42_PEND     *(U32 *)(extbase + 0x0F48)
#define      EXT_INT43_PEND     *(U32 *)(extbase + 0x0F4C)

//定时器

#define   timerbase  0x139D0000
#define   TCFG0      *(U32 *)(timerbase + 0x0000 )
#define   TCFG1      *(U32 *)(timerbase + 0x0004 )
#define   TCON       *(U32 *)(timerbase + 0x0008 )
#define   TCNTB0     *(U32 *)(timerbase + 0x000C )
#define   TCMPB0     *(U32 *)(timerbase + 0x0010 )
#define   TCNTO0     *(U32 *)(timerbase + 0x0014 )
#define   TCNTB1     *(U32 *)(timerbase + 0x0018 )
#define   TCMPB1     *(U32 *)(timerbase + 0x001C )
#define   TCNTO1     *(U32 *)(timerbase + 0x0020 )
#define   TCNTB2     *(U32 *)(timerbase + 0x0024 )
#define   TCMPB2     *(U32 *)(timerbase + 0x0028 )
#define   TCNTO2     *(U32 *)(timerbase + 0x002C )
#define   TCNTB3     *(U32 *)(timerbase + 0x0030 )
#define   TCMPB3     *(U32 *)(timerbase + 0x0034 )
#define   TCNTO3     *(U32 *)(timerbase + 0x0038 )
#define   TCNTB4     *(U32 *)(timerbase + 0x003C )
#define   TCNTO4     *(U32 *)(timerbase + 0x0040 )
#define   TINT_CSTAT *(U32 *)(timerbase + 0x0044 )

//ADC register

#define    adcbase   0x126C0000
#define    ADCCON    *(U32 *)(adcbase + 0x0000)
#define    ADCDLY    *(U32 *)(adcbase + 0x0008)
#define    ADCDAT    *(U32 *)(adcbase + 0x000C)
#define    CLRINTADC *(U32 *)(adcbase + 0x0018)
#define    ADCMUX    *(U32 *)(adcbase + 0x001C)

//interrupt combiner register
#define   combinerbase   0x10440000
#define    IESR0 *(U32 *)(combinerbase + 0x0000 )
#define    IECR0 *(U32 *)(combinerbase + 0x0004 )
#define    ISTR0 *(U32 *)(combinerbase + 0x0008 )
#define    IMSR0 *(U32 *)(combinerbase + 0x000C )
#define    IESR1 *(U32 *)(combinerbase + 0x0010 )
#define    IECR1 *(U32 *)(combinerbase + 0x0014 )
#define    ISTR1 *(U32 *)(combinerbase + 0x0018 )
#define    IMSR1 *(U32 *)(combinerbase + 0x001C )
#define    IESR2 *(U32 *)(combinerbase + 0x0020 )
#define    IECR2 *(U32 *)(combinerbase + 0x0024 )
#define    ISTR2 *(U32 *)(combinerbase + 0x0028 )
#define    IMSR2 *(U32 *)(combinerbase + 0x002C )
#define    IESR3 *(U32 *)(combinerbase + 0x0030 )
#define    IECR3 *(U32 *)(combinerbase + 0x0034 )
#define    ISTR3 *(U32 *)(combinerbase + 0x0038 )
#define    IMSR3 *(U32 *)(combinerbase + 0x003C )
#define    IESR4 *(U32 *)(combinerbase + 0x0040 )
#define    IECR4 *(U32 *)(combinerbase + 0x0044 )
#define    ISTR4 *(U32 *)(combinerbase + 0x0048 )
#define    IMSR4 *(U32 *)(combinerbase + 0x004C )


//uart register
//0x1380_0000, 0x1381_0000, 0x1382_0000, 0x1383_0000, 0x1384_0000

#define   uartbase   0x13800000
#define    ULCONn    *(U32 *)(uartbase + 0x0000 )
#define    UCONn     *(U32 *)(uartbase + 0x0004 )
#define    UFCONn    *(U32 *)(uartbase + 0x0008 )
#define    UMCONn    *(U32 *)(uartbase + 0x000C )
#define    UTRSTATn  *(U32 *)(uartbase + 0x0010 )
#define    UERSTATn  *(U32 *)(uartbase + 0x0014 )
#define    UFSTATn   *(U32 *)(uartbase + 0x0018 )
#define    UMSTATn   *(U32 *)(uartbase + 0x001C )
#define    UTXHn     *(U32 *)(uartbase + 0x0020 )
#define    URXHn     *(U32 *)(uartbase + 0x0024 )
#define    UBRDIVn   *(U32 *)(uartbase + 0x0028 )
#define    UFRACVALn *(U32 *)(uartbase + 0x002C )
#define    UINTPn    *(U32 *)(uartbase + 0x0030 )
#define    UINTSPn   *(U32 *)(uartbase + 0x0034 )
#define    UINTMn    *(U32 *)(uartbase + 0x0038 )



//my uart function
//
void putchar(char ch);
char getchar(void);
void gets(char *buffer);
void puts(const char *str);
int myprintf(const char *fmt , ...);
void Init_Serial(void);
void Serial_Operation(void);

//uboot uart function
void serial_putc_dev(const char c, const int dev_index);
int serial_getc_dev(const int dev_index);
void serial_puts_dev(const char *s, const int dev_index);
int serial_init_dev(const int dev_index);

//i2c register
//0x1386_0000, 0x1387_0000, 0x1388_0000, 0x1389_0000,
//0x138A_0000, 0x138B_0000, 0x138C_0000, 0x138D_0000, 0x138E_0000

#define   i2cbase 	0x13870000
#define   I2CCONn   *(U32 *)(i2cbase + 0x0000 )
#define   I2CSTATn  *(U32 *)(i2cbase + 0x0004 )
#define   I2CADDn   *(U32 *)(i2cbase + 0x0008 )
#define   I2CDSn    *(U32 *)(i2cbase + 0x000C )
#define   I2CLCn    *(U32 *)(i2cbase + 0x0010 )


#endif  //_RES_H
