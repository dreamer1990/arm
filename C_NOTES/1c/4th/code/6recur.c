#include <stdio.h>

int age(int n)
{
    int tmp = 0;
    if (1 == n) 
        return 10;

    printf("%d\n", n);
    tmp = age(--n) + 2;
    printf("%d\n", n);

    return tmp;
}

int main(void)
{
    printf("age(5):  %d\n", age(5));
    return 0;
}
