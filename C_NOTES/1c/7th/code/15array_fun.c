#include <stdio.h>

//函数指针变量类型
typedef int (*fun_t)(int, int);

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int mul(int x, int y)
{
    return x * y;
}

int div(int x, int y)
{
    return x / y;
}

//指针数组
int main(void)
{
    //函数指针数组
    fun_t arr[4] = {add, sub, mul, div};
    char *s[4] = {"a + b = %2d\n", "a - b = %2d\n", "a * b = %2d\n", "a / b = %2d\n"};
    int a = 3;
    int b = 4;
    int i = 0;

    for (i = 0; i < 4; i++)
    {
        //a[i](a, b) --> a[i]是函数的入口地 
        //a[0] 等价于add
        //a[0](a, b)等价于add(a, b)
        printf(s[i], arr[i](a, b)); 
    }

    return 0;
}
