#include <stdio.h>

/*
 *13. 输入一个无符号整数, 判定该整数是否回文数
 *unsigned long
 *ex: 1, 11, 121, 12321,
 *
 */

int main(void)
{

   unsigned long num;
   unsigned long n1, n;


    printf("please input a number:   \n");
    scanf("%lu", &num);
    printf("num = %lu\n", num);

    n1 = 0;
    n = num;
    //相当于将一个整形颠倒  1234  ---> 4321
    while(n)
    {
        n1 = n1 * 10 +  n % 10;
        n /= 10;
    }

    if (n1 == num)
    {
        printf("%d是回文数...\n"); 
    }
    else
    {
        printf("%d不是回文数..\n"); 
    }

    return 0;
}
