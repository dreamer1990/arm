#include <stdio.h>

int main(void)
{
    int a = 3;
    int b = 4;


    //不能通过p修改p所指向的变量的值,但是p的值可以改变
    //与const int *p2等价
    int const *p = NULL;
    p = &a;
    printf("*p = %d\n", *p);

    p = &b;
    printf("*p = %d\n", *p);
    //错误：向只读位置赋值
    //*p = 100;

    //不能修改p的值,但是可以通过p间接修改变量的值
    int * const p1 = &a;
    printf("a = %d *p1 = %d\n", a, *p1);
    *p1 = 88; //通过p1间接修改变量的值
    printf("a = %d  *p1 = %d\n", a, *p1);
    //错误：向只读变量 ‘p1’ 赋值
    //p1 = &b;

    //不能通过p修改p所指向的变量的值,但是p的值可以改变
    const int *p2 = NULL;
    p2 = &b;
    printf("b = %d  *p2 = %d\n", b, *p2);
    p2 = &a;
    printf("a = %d  *p2 = %d\n", a, *p2);
    //错误：向只读位置赋值
    //*p2 = 100;

    //不能改变p3的值,也不能通过p3间接改变变量的值
    //与const int const * const p4等价
    int const * const p3 = &a;

    //错误：向只读变量 ‘p3’ 赋值
    //p3 = &b;
    //错误：向只读位置赋值
    //*p3 = 100;

    const int const * const p4 = &b;
    //错误：向只读变量 ‘p4’ 赋值
    //p4 = &a;
    //错误：向只读位置赋值
    //*p4 = 88;

    return 0;
}
