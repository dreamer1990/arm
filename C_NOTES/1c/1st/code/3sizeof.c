#include <stdio.h>

// sizeof: 求类型所占的字节数 sizeof是运算符
// sizeof (type)
// sizeof (变量名)
// sizeof 变量名

// char         1  字符类型         %c
// int          4  整形类型         %d  %i
// short        2  短整形           %d  %i
// long         4  长整形           %ld  
// long long    8  长长整形         %lld
// float        4  单精度浮点类型   %f
// double       8  双精度浮点类型   %lf
// long double  12 长双精度浮点类型 %lf

int main(void)
{
    //%d 整形
    printf("sizeof(char):  %d\n", sizeof(char));
    printf("sizeof(int):  %d\n", sizeof(int));
    printf("sizeof(short): %d\n", sizeof(short));
    printf("sizeof(long):  %d\n", sizeof(long));
    printf("sizeof(long long): %d\n", sizeof(long long));



    printf("sizeof(float): %d\n" ,sizeof(float));
    printf("sizeof(double): %d\n", sizeof(double));
    //printf("sizeof(long float): %d\n", sizeof(long float));
    printf("sizeof(long double): %d\n", sizeof(long double));



    return 0;
}
