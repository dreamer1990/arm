#include <stdio.h>

//值传递
int swap(int x, int y)
{
    printf("x = %d  y = %d\n", x, y);
    x ^= y;
    y ^= x;
    x ^= y;
    printf("x = %d  y = %d\n", x, y);
}

//只是改变了x和y的指向,根本没有间接的改变a和b的值
int swap_v1(int *x, int *y)
{
    int *tmp = x;
    printf("*x = %d  *y = %d\n", *x, *y);
    x = y;
    y = tmp;
    printf("*x = %d  *y = %d\n", *x, *y);
}
//传地址
int swap_v2(int *x, int *y)
{
    int tmp;

    printf("*x = %d  *y = %d\n", *x, *y);
    tmp = *x;
    *x = *y;
    *y = tmp;

    printf("*x = %d  *y = %d\n", *x, *y);
}

int main(void)
{

    int a = 3;
    int b = 4;

    printf("a = %d  b = %d\n", a, b);
    //swap(a, b);
    //swap_v1(&a, &b);
    swap_v2(&a, &b);
    printf("a = %d  b = %d\n", a, b);

    return 0;
}
