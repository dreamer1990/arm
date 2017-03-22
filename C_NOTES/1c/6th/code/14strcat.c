#include <stdio.h>


//字符串连接函数
char *my_strcat(char *dest, const char *src)
{
    char *tmp = dest;
    while(*tmp++)
        ;
    tmp--;
    while(*tmp++ = *src++)
        ;
    return dest;
}
//字符串连接函数
char *my_strncat(char *dest, const char *src, size_t n)
{
    char *tmp = dest;

    if (n > 0)
    {
        while(*tmp && tmp++)
            ;
        while(n)
        {
            if ((*tmp = *src) != '\0')
            {
                src++; 
            }
            tmp++; 
            n--;
        }

        *tmp = '\0';
    }

    return dest;
}

//返回字符串的长度
size_t my_strlen(const char *s)
{
    const char *tmp = s;

    while(*tmp++)
        ;

    return tmp - s - 1;
}

//判断两个字符串的大小
int my_strcmp(const char *s1, const char *s2)
{
   while(*s1) 
   {
        if (*s1 == *s2) 
            s1++, s2++;
        else
            return *s1 - *s2 > 0 ? 1 : -1;
   }
    //相等的情况
    return 0;
}

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    while(n && *s1)
    {
        if (*s1 == *s2)
            s1++, s2++;
        else
            return *s1 - *s2 > 0 ? 1 : -1;
        n--; 
    }

    //相等的情况
    return 0;
}



int main(void)
{
    char src[32] = "Hello ";

    //printf("%s\n", my_strcat(src, "world"));
    printf("%s\n", my_strncat(src, "Hello", 3));

    printf("strlen:  %d\n", my_strlen("hello world"));
    printf("strcmp:  %d\n", my_strcmp("AAAA", "BBBB"));
    printf("strcmp:  %d\n", my_strcmp("aaa", "aaa"));
    printf("strcmp:  %d\n", my_strcmp("aaaa", "aaa"));

    printf("strncmp: %d\n", my_strncmp("aaabbb", "aaacccc", 3));
    printf("strncmp: %d\n", my_strncmp("aaabbb", "aaacccc", 4));
    return 0;
}

