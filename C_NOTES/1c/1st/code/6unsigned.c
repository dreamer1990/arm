#include <stdio.h>

int main(void)
{
    unsigned int a = -1;
   //0xff代表16进制的数 
    unsigned int b = 0xff;

    int c = -1;


    //%u 以无符号输出
    printf("%u\n", a);
    //%d是有符号输出
    printf("%d\n", a);
    //十六进制输出  没有前缀0x
    printf("%x\n", a);
    //十六进制输出  有前缀0x
    printf("%#x\n", a);

    printf("b = %d\n", b);
    printf("b = %u\n", b);

    //有符号的数字 以没有符号的形式输出
    printf("c = %u\n", c);

    return 0;
}
