#include <stdio.h>

int main(void)
{
    unsigned long a = 0x11223344;
    unsigned char *p = (char *)&a;

    //判断大小端的问题
    if (*p == 0x44)
        printf("当前系统是小端模式..\n");
    else
        printf("当前系统是大端模式..\n");

    return 0;
}
