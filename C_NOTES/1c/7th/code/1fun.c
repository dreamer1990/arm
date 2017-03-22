#include <stdio.h>


//函数指针: 指向函数的指针


//fun是一个函数名  就是这个函数的入口地址
//fun是一个标号,标记函数的入口地址
int fun(void)
{
    printf("hello world\n");

    return 0;
}

int main(void)
{

    //fun与&fun数值上相等
    printf("fun:  %p\n", fun);
    printf("printf:  %p\n", printf);
    printf("main:  %p\n", main);
    printf("&fun:  %p\n", &fun);

    printf("return:  %d\n", fun());

    return 0;
}
