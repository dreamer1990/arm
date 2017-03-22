#include <stdio.h>

//赋值兼容练习
int main(void)
{
    //b是一个int变量  
    int b;
    //a是一个数组  元素类型是int 有10个元素
    int a[10];

    //c是一个二维数组  数组元素类型是int 有100个元素
    int c[10][10];

    //d是一个三维数组  数组元素类型是int 有1000个元素
    int d[10][10][10];

    //e是一个一维数组  数组元素是int *类型
    int *e[10];
    //f是一个一维数组  数组元素类型是int **
    int **f[10];

    int *p = &b;
    int *p1 = a;
    int (*p2)[10] = c;

    int (*p3)[10][10];
    p3 =  d;

    int **p4;
    p4 = e;

    int ***p5 = NULL;
    p5 = f;




    return 0;
}
