#include <stdio.h>

int main(void)
{
    int a = 3;
    int b = 4;

    int *p = NULL;

    p = &a;
    printf("a = %d  *p = %d\n", a, *p);

    //p是一个指针变量 p的指向可以改变
    p = &b;
    printf("b = %d  *p = %d\n", b, *p);

    return 0;
}
