#include <stdio.h>

//函数指针的别名
typedef int(*fun_t)(int, int);

int max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x > y ? y : x;
}

int test1(int x)
{
    printf("hahhah  error...\n");
    return 0;
}


int main(void)
{
    int a = 10;
    int b = 20;

    //定义两个函数指针变量
    fun_t pf = NULL;
    int (*pf1)(int, int) = NULL;

    //赋值一定要兼容
    pf = max;
    pf1 = max;
    printf("max:  %d\n", pf(a, b));
    printf("max:  %d\n", pf1(a, b));

    //赋值不兼容  可能得不到预期的结果
    pf = test1;
    printf("test:  %d\n", pf(a, b));


    return 0;
}
