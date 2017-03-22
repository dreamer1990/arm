#include <stdio.h>

int main(void)
{

    int n;

    printf("please input a number: \n");
    scanf("%d", &n);

    // n % 2 如果为0 则为偶数
    if (n % 2 == 0)
    {
        printf("%d 是偶数\n", n); 
    }
    else
    {
        printf("%d 是奇数\n", n); 
    }

    return 0;
}
