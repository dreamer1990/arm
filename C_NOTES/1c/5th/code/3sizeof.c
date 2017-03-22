#include <stdio.h>

//sizeof: 是一个运算符

int main(void)
{

    //在32位系统中所有的指针类型都是4个字节
    //在64位系统中所有的指针类型都是8个字节
    //4
    printf("sizeof(int *):  %d\n", sizeof(int *));
    //4
    printf("sizeof(long *):  %d\n", sizeof(long*));
    //4
    printf("sizeof(char *): %d\n", sizeof(char *));
    //4
    printf("sizeof(float*):  %d\n", sizeof(float*));
    //4
    printf("sizeof(double*):  %d\n", sizeof(double*));

    //没有void类型的变量
    //void a;
    printf("sizeof(void *):  %d\n", sizeof(void *));




    return 0;
}
