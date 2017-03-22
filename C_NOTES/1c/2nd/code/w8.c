#include <stdio.h>

/*
 *12. 输出所有的水仙花数。所谓的水仙花数是指一个3位数，其各位数字立方和等于该数本身。
 *153 = 1 ^ 3 + 5 ^ 3 + 3 ^ 3
 *
 */

int main(void)
{
    int sum, a;
    int i, j;

    //控制所有的三位数
    for (i = 100; i <= 999; i++)
    {
        //置0
        sum = 0;
        a = i;
        while(a) 
        {
            sum = sum + (a % 10) * (a % 10) * (a % 10);
            a /= 10;
        }

        //输出水仙花数
        if (i == sum)
        {
            printf("%2d  ", i);     
        }
    }
    
    putchar('\n');


    return 0;
}
