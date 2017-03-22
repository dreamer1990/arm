#include <stdio.h>

//定义函数指针类型,fun_t是函数指针类型
typedef int(*fun_t)(int, int);

//返回两个数中较大的一个数
int max(int x, int y)
{
    return x > y ? x : y;
}

//返回两个数中较小的一个数
int min(int x, int y)
{
    return x > y ? y : x;
}

int main(void)
{
    int choice;
    int a = 3;
    int b = 4;
    fun_t p = NULL;
    printf("please make a choice[1-->max  2 --> min]\n");
    scanf("%d", &choice);

    if (1 == choice)
    {
        //将max的入口地址给p
        p = max;
        printf("max(a,b) = %d\n", p(a, b));
    }
    else
    {
        //将min的入口地址给p
        p = min;
        printf("min(a, b) = %d\n", p(a, b));
    }
        

    return 0;
}
