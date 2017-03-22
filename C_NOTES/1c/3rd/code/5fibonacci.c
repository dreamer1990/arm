#include <stdio.h>

/*
 *1. 求Fibonacci数列的前40项。这个数列有如下特点:第1、2两个数为1、1，从第3个数开始，该数是前面两个数之和。
 *
 */

int  main(void)
{
    int a[40] = {1, 1};
    int i = 0;

    //计算fibonacii每一个元素的值,从第3项开始
    for (i = 2; i < 40; i++)
    {
        // a[i - 1] 就是a[i]前面第一个元素
        // a[i - 2] 就是a[i]前面第二个元素
        a[i] = a[i - 1] + a[i -2]; 
    }

    //输出数组中的值
    for (i = 0; i < 40; i++)
    {
        //每输出4个元素之后就换行
        if (i % 4 == 0 && 0 != i) 
            putchar('\n');
        printf("%10d  ", a[i]);
    }

    //换行
    printf("\n");

    return 0;
}
