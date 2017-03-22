#include <stdio.h>


//二级指针: 指向指针的指针

int main(void)
{
    int a = 88;
    int *p = &a;
    int *p1 = (int *)&p;

    //p2的类型是int **
    //p2指向的是int *类型
    //*p2的类型是int *
    //*p2指向是int 类型
    //**p2是一个int类型
    int **p2 = NULL;
    p2 = &p;

    printf("&a:  %p  p = %p\n", &a, p);
    printf("a = %d   *p = %d\n", a, *p);
    printf("*p = %d  *p1 = %p\n", *p, *p1);

    printf("&p = %p\n", &p);
    printf("p2 = %p  *p2 = %p\n", p2, *p2);
    printf("*p2 = %p  **p2 = %d\n", *p2, **p2);

    int **p3 = NULL;
    //段错误
    //*p3 = &a;
    //printf("**p3 = %d\n", **p3);


    return 0;
}
