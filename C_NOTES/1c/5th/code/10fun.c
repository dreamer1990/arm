#include <stdio.h>

int *fun(void)
{
    int a = 3;

    printf("a = %d\n", a);

    //&a是int *类型
    //警告：函数返回局部变量的地址
    return &a;
}

int main(void)
{

    //局部变量的地址没有意义
    int *p = fun();

    printf("hello world\n");
    printf("*p = %d\n", *p);

    return 0;
}
