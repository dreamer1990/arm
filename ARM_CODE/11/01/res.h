
#ifndef _RES_H
#define _RES_H

typedef volatile unsigned int U32 ; 
typedef volatile unsigned short U16 ; 
typedef volatile unsigned char  U8 ; 

#define   NULL   0
typedef unsigned int size_t ; 
typedef unsigned long  ulong ; 

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





#endif  //_RES_H
