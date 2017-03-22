#include <stdio.h>

//将字符串src拷贝到dest中, 并且dest要足够的长
char *my_strcpy(char *dest, const char *src)
{
    char *s = dest;

    while(*dest++ = *src++)
        ;
    return s;
}

char *my_strncpy(char *dest, const char *src, size_t n)
{
    char *tmp = dest;

    while(n)
    {
        //如果遇到了\0将后面的所有内存都清空为0
        if ((*tmp = *src) != '\0') 
            src++;
        tmp++;
        n--;
    }

    *tmp = '\0';

    return dest;
}


//清空内存
void *my_memset(void *s, int c, size_t n)
{
    int i = 0;
    while(i < n)
    {
        *((char *)s + i) = c;
        i++;
    }
   return s;
}


int main(void)
{
    char src[] = "hello world";
    char dest[64] = "Hello aaaaaaaa";
    char *s;
    s = dest;
    //printf("%s\n", my_strcpy(s, src));

    //my_memset(dest, 0, 64);
    //printf("dest:  %s\n", dest);

    my_strncpy(dest, src, 5);
    printf("strncpy ====>  %s\n", dest);

    return 0;
}
