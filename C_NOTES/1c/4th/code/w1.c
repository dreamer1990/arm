#include <stdio.h>
#include <math.h>


/*
 *1. 封装一个函数，判断一个数是否为质数.并且输出1 -- 100之间的质数
 *    int prim(int n);
 *    质数:
 *        Yes:
 *            return 0
 *        No:
 *            return -1;
 */

//函数的定义
int prim(int n)
{
    int i = 0;
    int ret = 0;

    //判断是否为质数
    for (i = 2; i <= n / 2; i++)
    {
        //能够被整除就不是质数
        if (n % i == 0) 
            break;
    }

    if (i <= n / 2)
        ret = -1;
    else
        ret = 0;
    
    return ret;
}

//-lm  链接数学库
//编译的时候  gcc w1.c -lm
int prim_v1(int n)
{
    int i = 0;
    int ret = 0;

    //判断是否为质数
    for (i = 2; i <= sqrt(n); i++)
    {
        //能够被整除就不是质数
        if (n % i == 0) 
            break;
    }

    if (i <= sqrt(n))
        ret = -1;
    else
        ret = 0;
    
    return ret;
}

int main(void)
{
    int i = 0;

    for (i = 2; i <= 100; i++)
    {
        //如果是质数就输出
        if (prim_v1(i) == 0)
        {
            printf("%d  ", i); 
        }
    }

    putchar('\n');

    return 0;
}
