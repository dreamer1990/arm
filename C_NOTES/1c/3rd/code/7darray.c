#include <stdio.h>

/*
 *二维数组的定义:
 *    类型 数组名[常量表达式][常量表达式];
 */
int main(void)
{
    //定义一个数组 数组名为a, 有3行4列 
    int a[3][4];

    //48 整个数组占的字节数
    printf("sizeof(a): %d\n", sizeof(a));
    //16 每一行占的字节数
    printf("sizeof(a[0]): %d\n", sizeof(a[0]));
    //4  数组中每个元素所占的字节数
    printf("sizeof(a[0][0]: %d\n", sizeof(a[0][0]));
    //3 二维数组中第一维的大小 48 / 16
    printf("sizeof(a1): %d\n", sizeof(a) / sizeof(a[0]));
    //4 二维数组中第二维的大小 16 / 4
    printf("sizeof(a2): %d\n", sizeof(a[0]) / sizeof(a[0][0]));
    //12 二维数组中元素的个数  48 / 4
    printf("sizeof(a3):  %d\n", sizeof(a) / sizeof(a[0][0]));


    //a和&a都是数组的首地址的值
    printf("a:  %p  &a:  %p\n", a, &a);
    //a + 1 指向第2行   a + 4 * 4 
    //&a + 1  a + 3 * 4 * 4
    printf("a + 1:  %p  &a + 1 = %p\n", a + 1, &a + 1);

    printf("a[0]: %p  &a[0]: %p\n", a[0], &a[0]);
    //a[0] + 1 --> a[0] + 4
    //&a[0] + 1 指向下一行  &a[0] + 4 * 4
    printf("a[0] + 1: %p  &a[0] + 1: %p\n", a[0] + 1, &a[0] + 1);

    printf("a[0][0]: %p  &a[0][0]: %p\n", a[0][0], &a[0][0]);
    printf("a[0][0] + 1: %p  &a[0][0] + 1: %p\n", a[0][0] + 1, &a[0][0] + 1);

    return 0;
}
