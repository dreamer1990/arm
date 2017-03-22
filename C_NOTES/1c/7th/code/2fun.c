#include <stdio.h>

// typedef 给类型一个别名,不是定义新的类型

//Uint不是类型,而是一个unsigned int类型的变量
unsigned int Uint;
//uint不是变量, 而是一个unsigned int类型的别名
typedef unsigned int uint;


typedef int (*fun_t)(void);

//int (void) *p = NULL;
//int(*)(void) p = NULL;
//p是函数指针变量,指向返回值为int类型 参数为void的函数
int (*p_fun)(void) = NULL;


//自定义的函数
int test(void)
{
    printf("hello world\n");
    return 0;
}

int test1(int a)
{
    printf("test1 a = %d\n", a);
}

int main(void)
{

    //int *p;

    //相当于unsigned int p = 0x1234478
    uint p = 0x1234478;

    printf("p = %p\n", p);

    p_fun = test;

    //hello world
    //p_fun()与(*p_fun)()等价
    p_fun();
    (*p_fun)();

    //p_fun指向test1这个函数
    //警告：从不兼容的指针类型赋值
    //p_fun = test1;

    return 0;
}
