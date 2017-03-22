#include <stdio.h>

// ... 代表变参
//int printf(const char *format, ...);

/*
 *        %d   signed int
 *        %ld  long
 *        %lld long long
 *        %llu unsigned long long
 *        %u   unsigned int
 *        %o   八进制
 *        %x   十六进制
 *        %p   输出地址
 *        %f   float double
 *        %s   字符串
 *        %c   char
 *        %%   %
 *
 */

//编译的时候指定为c99标准
//gcc 18printf.c -std=c99

int main(void)
{
    char ch = 'A';
    int  n = 97;
    long l = 1234568903;
    //long long ll = 1234567890145678; //c99支持类型

    float f = 3.24f;
    double d = 3.24;

    printf("ch = %c ch = %d\n", ch, ch);
    printf("n = %d n = %c\n", n, n);
    printf("l = %ld\n", l);
    printf("l = %d\n", l);
   // printf("ll = %d ll = %lld\n", ll, ll);


    printf("hex: %#x  oct: %#o\n", n, n);

    // n2可能会是随机
    printf("n1 = %d  n2 = %c\n", n);
    //如果参数多于%匹配 多余的参数就丢弃
    printf("n1 = %d  n2 = %c\n", n, n, n);

    return 0;
}
