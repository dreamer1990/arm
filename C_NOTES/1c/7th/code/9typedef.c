#include <stdio.h>

//typedef 是一个关键字
//并不是定义新的类型 他只是已经存在的类型取个别名
//typedef 类型名  类型别名

typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long uint_64;

//A是int[10]类型
typedef int A[10];
//B是int(*)[10]类型
typedef int (*B)[10];

int main(void)
{
    //与 unsigned int a等价
    uint a;
    int i = 0;

    //与int array[10]等价
    //A相当于一个数组类型
    A array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //警告：从不兼容的指针类型初始化
    //B b = array;
    B b = &array;

    a = 100;
    printf("a = %d\n", a);

    for(i = 0; i < 10; i++)
    {
        printf("%d  ", array[i]); 
    }
    putchar('\n');
    printf("===================\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d  ", (*b)[i]); 
    }
    putchar('\n');


    return 0;
}
