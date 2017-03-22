#include <stdio.h>

int main(void)
{
    int i = 3;
    int a[1] = {4};
    int d[0];
    int b = 5;

    //数组名不是变量，它只是一个数组的首地址
    printf("&i: %p  a:  %p  d: %p  &b:  %p\n", &i, a, d, &b);

    //数组可以越界访问，编译器不做越界检查,建议一般不要越界
    printf("%d  %d  %d\n", a[1], a[0], a[-1]);

    printf("%d  %d  %d\n", d[1], d[0], d[-1]);

    //越界可能更改其他变量的值
    a[1] = 111;
    a[0] = 222;
    a[-1] = 333;

    printf("i: %d  a[0]: %d b: %d\n", i, a[0], b);

    return 0;
}
