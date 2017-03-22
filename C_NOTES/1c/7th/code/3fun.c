#include <stdio.h>


//fun_t是类型 不是变量
//fun_t相当于int(int, int)函数类型
//fun_t p = NULL与 int(*p1)(int, int)等价
typedef int(*fun_t)(int, int);

//相加的函数
int add(int x, int y)
{
    return x + y;
}

//相减的函数
int sub(int x, int y)
{
    return x - y;
}

int main(void)
{

    int a = 3;
    int b = 4;
    //fun_t就是一个函数类型
    // p是fun_t类型的指针变量
    fun_t p = NULL;

    //p是函数指针变量 它是指向函数的
    //add代表函数的入口地址
    p = add;
    printf("a + b = %d\n", p(a, b)); 
    printf("a + b = %d\n", (*p)(a, b));

    printf("====================\n");
    //p = add 与 p = &add是数值上等价的
    p = &add;
    //printf("a + b = %d\n", p(a, b));
    printf("a + b = %d\n", (*p)(a, b));

    printf("a + b = %d\n", (*&add)(a, b));


    printf("=========================\n");
    p = sub;
    printf("a - b = %d\n", p(a, b));


    //错误 add(a, b)返回的是一个具体的数值
    //p = add(a, b);
    //错误：赋值运算中的左值无效
    //*p = add;

    return 0;
}
