
#ifndef _RES_H
#define _RES_H

typedef volatile unsigned int U32 ; 
typedef volatile unsigned short U16 ; 
typedef volatile unsigned char  U8 ; 

#define   NULL   0
typedef unsigned int size_t ; 
typedef unsigned long  ulong ; 

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





#endif  //_RES_H
