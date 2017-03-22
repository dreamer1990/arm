#include <stdio.h>


/*
 *15. 求Fibonacci数列的前40项。这个数列有如下特点:第1、2两个数为1、1，从第3个数开始，该数是前面两个数之和。
 *
 */

int main(void)
{

    int n1, n2;
    int i = 0;

    n1 = 1;
    n2 = 1;
    //每次输出2个数  
    for (i = 0; i < 20; i++)
    {
        if (i % 2 == 0 && i != 0)
        {
            printf("\n"); 
        }
    
        printf("%10d  %10d  ", n1, n2); 

        n1 = n1 + n2;
        n2 = n2 + n1;
    }

    putchar('\n');

    return 0;
}
