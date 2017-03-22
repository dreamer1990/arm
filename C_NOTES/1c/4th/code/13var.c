#include <stdio.h>

/*
 *11. 变量的声明和定义
 *    一般为了叙述方便，把建立存储空间的变量声明称定义，而把不需要建立存储空间的声明称为声明
 *    在函数中出现的对变量的声明(除了用 extern 声明的以外)都是定义
 *
 */

//相当于声明
int a;
int a;
int a;

//相当于定义
//int a = 10;

int add_v1(void)
{
    extern int a;

    printf("a = %d\n", a);
}


int main(void)
{
    //在函数中可以声明外部变量
    //extern int a;

    add_v1();
    printf("extern a:  %d\n", a);

    return 0;
}
