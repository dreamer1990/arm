#include <stdio.h>

int swap(int x, int y)
{
    int tmp;

    tmp = x;
    x = y;
    y = tmp;

    printf("====> int swap:  x =  %d  y = %d\n", x, y);

    return 0;
}

int main(void)
{
    int a = 3;
    int b = 4;

    printf("a = %d  b = %d\n", a, b);
    //形参改变不了实参的值
    swap(a, b);
    printf("a = %d  b = %d\n", a, b);

    return 0;
}
