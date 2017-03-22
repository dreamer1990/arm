#include <stdio.h>

//gcc -E a.c -o a.i

/*
 *2. 宏定义
 *    a. 不带参数的宏定义
 *    宏定义一般形式为:
 *        #define 标识符 字符串
 *        例如：# define PI 3.1415926
 *
 */


//这个标识符（名字）称为“宏名”。
//在预编译时将宏名替换成字符串的过程称为“宏展开”。#define是宏定义命令。


//不带参数的宏定义,只是在预处理的时候进行简单的宏替换
#define SIZE 100

#define PI 3.1415926535897

int main(void)
{

    //printf("SIZE: %d\n", 100);
    printf("SIZE: %d\n", SIZE);

    //替换成3 * 3 * 3.1415926535897
    printf("area:  %lf\n", 3 * 3 * PI);

    return 0;
}
