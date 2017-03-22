#include <stdio.h>


/*
 *6. 求两个数的最大公约数和最小公倍数.
 *    
 *    int n1, n2;
 */

int main(void)
{
    int n, m;
    int i;
    int min;

    printf("please input two number:   \n");
    scanf("%d  %d", &n, &m);

    min = n > m ? m : n;
    for (i = min; i > 0; i--)
    {
        if (m % i == 0 && n % i == 0) 
        {
            printf("%d 和 %d的最大公约数为:  %d\n", n, m, i); 
            break; //退出本层循环
        }
    }

    if (i == 0)
    {
        i = 1;
        printf("%d 和 %d 的最大公约数为:  %d\n", n, m, i);
    }
    

    printf("%d 和 %d的最小公倍数为:  %d\n", n, m, n * m / i);

    //辗转相除法
    //min = n > m ? m : n;
    //n是最小的  m是最大的
    if(m < n)
    {
        min = m;
        m = n;
        n = min;
    }

    while(n)
    {
        min = m % n; 
        m = n;
        n = min;
    }

    printf("最大公约数为；  %d\n", m);

    return 0;
}
