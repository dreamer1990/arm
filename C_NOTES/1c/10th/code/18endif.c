#include <stdio.h>
#include <string.h>

#define SIZE 128

#define UPPER

int main(void)
{
    char buf[SIZE];
    int i = 0;

    printf("please input a string:  \n");

    //从标准输入获取一串字符串
    fgets(buf, SIZE, stdin);

    #ifdef UPPER
        for (i = 0; i < strlen(buf); i++) 
        {
            buf[i] >= 'a' && buf[i] <= 'z' ? putchar(buf[i] - 32) : putchar(buf[i]); 
        }
       // putchar('\n');
    #else
        for (i = 0; i < strlen(buf); i++)
        {
            buf[i] >= 'A' && buf[i] <= 'Z' ? putchar(buf[i] + 32) : putchar(buf[i]);
        }
       // putchar('\n');
    #endif


    return 0;
}
