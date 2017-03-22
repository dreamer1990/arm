#include <stdio.h>

//fun_t是函数指针类型
typedef int(*fun_t)(int, int);

/*
 *    2. 回调函数
 *
 *    用指向函数的指针作函数参数
 *
 *    指向函数的指针变量的一个重要用途是把函数的地址作为参数传递到其他函数
 *
 *    指向函数的指针可以作为函数参数，把函数的入口地址传递给形参，这样就能够在被调用的函数中使用实参函数
 *
 */

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

//回调函数
//fun_t p是函数指针, p是fun函数的一个形参
int fun(int x, int y, fun_t p)
{
    return p(x, y);
}

int main(void)
{
    int a = 3;
    int b = 4;
    int result;

    //调用add
    result = fun(a, b, add);
    printf("a + b = %d\n", result);

    //调用sub
    result = fun(a, b, sub);
    printf("a - b = %d\n", result);

    return 0;
}
