#include <stdio.h>

/*
 *    引用指针变量：
 *
 *    在引用指针变量时，可能有三种情况：
 *    a. 给指针变量赋值。如：p=&a;
 *    b. 引用指针变量指向的变量。如有
 *        p=&a;  *p=1;
 *        则执行printf(“%d”,*p);  将输出1
 *    c. 引用指针变量的值。如：printf(“%o”,p);
 *    
 */

int main(void)
{
    int a = 3;
    int *p = &a;

    //p1是一个野指针
    int *p1;

    // a 与*p等价
    printf("a = %d  *p = %d\n", a, *p);

    //通过p间接访问a或者修改a的值
    *p = 88;
    printf("a = %d  *p = %d\n", a, *p);

    //p = NULL; //段错误
    p = (int *)&p;
    printf("a = %p  &p = %p  *p = %p\n", &a, &p, *p);

    //p1是一个野指针，原则上不能进行解引用 *p1
    printf("*p1 = %d\n", *p1);

    return 0;
}
