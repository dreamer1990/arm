#include <stdio.h>
#include <string.h>


char *my_strchr(const char *s, int c)
{
    while(*s) 
    {
        if (*s == c) 
        {
            return (char *)s;        
        }
        s++;
    }

    return NULL;
}

char *my_strrchr(const char *s, int c)
{
    const char *tmp = s;

    s = tmp + strlen(tmp);
    while(s != tmp)
    {
        if (c == *s) 
            return (char *)s;
        s--;
    }
    return NULL;
}


int main(void)
{
    char *s = "Hello world";

    //没有判断为NULL的情况
    printf("%s\n", my_strchr(s, 'o'));

    printf("%s\n", my_strrchr(s, 'o'));


    return 0;
}
