#include <stdio.h>


/*7. 输出1--100中所有的偶数,并且将所有的偶数相加,最后输出累加和*/

int main(void)
{
    int i = 2;
    int sum = 0;

    while(i < 101)
    {
        if (i % 2 == 0)
        {
            sum += i;  // 与sum = sum + i; 等价
            printf("%d  ", i);
        }
        i++;
    }

    printf("\nsum = %d\n", sum);

    printf("=======================\n");

    i = 2;
    sum = 0;
    while(i < 101)
    {
        printf("%d   ", i);
        sum += i; 
        i = i + 2; 
    }

    printf("\nsum = %d\n", sum);

    return 0;
}
