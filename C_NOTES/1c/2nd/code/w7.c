#include <stdio.h>
/*
 *是我们基本复合运算
 *^= &= |= <<= >>= 
 *s += a;  ==> s = s + a;
 *s -= a;  ==> s = s - a;
 *s *= a;  ==> s = s * a;
 *s /= a;  ==> s = s / a;
 *
 */

/*
 *11. 输出1 - 1000以内的完数(其真因子之和等于其自身)
 *   6: 1, 2, 3, == 6 = 1 + 2 + 3
 *
 */


int main(void)
{
    int i, j;
    int sum = 0;

    //循环1--1000以内
    for (i = 1; i<= 1000; i++)
    {
        sum = 0;
        //判断该数是否为完数 
        for (j = 1; j < i; j++)
        {
            if (i % j == 0) 
            {
                sum += j;  //sum = sum + j; 
            }
        }

        if (i == sum)
        {
            //输出完数
            printf("%2d  ", i); 
        }
    }

    putchar('\n');

    return 0;
}
