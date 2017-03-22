#include <stdio.h>

//形参改变不了实参
int swap(int *x, int *y)
{
    int *tmp = x;
    x = y;
    y = tmp;
}

int main(void)
{
    int a = 3;
    int b = 4;
    int *p1 = &a;
    int *p2 = &b;

    printf("p1 = %p  p2 = %p\n", p1, p2);
    swap(p1, p2);
    //p1 p2的值没有改变
    printf("p1 = %p  p2 = %p\n", p1, p2);

    return 0;
}
