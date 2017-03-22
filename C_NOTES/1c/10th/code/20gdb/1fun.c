#include <stdio.h>

int fun(int n)
{
    int i = 0;
    int sum = 0;

    for (i = 1; i <= n; i++)
    {
        sum += i; 
    }

    return sum;
}

int main(void)
{
    int sum = 0;
    int i = 0;

    for (i = 1; i <= 200; i++)
    {
        sum += i; 
    }

    printf("1 + 2 + 3... + 100 = %d\n", fun(100));

    printf("1 + 2 + 3 + ... + 200 = %d\n", sum);


    return 0;
}
