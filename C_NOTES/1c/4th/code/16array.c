#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/*
 *
 *     a. 数组元素作函数实参
 *     b. 数组名作函数参数
 *     除了可以用数组元素作为函数参数外，还可以用数组名作函数参数(包括实参和形参)
 *     用数组元素作实参时，向形参变量传递的是数组元素的值
 *     用数组名作函数实参时，向形参 传递的是数组首元素的地址
 *     c. 多维数组名作函数参数
 *
 */

//简单的宏替换
//sizeof(a[0] + 0)  --> sizeof(int *)
#define ARRAY_NUM(a) (sizeof(a) / sizeof(a[0] + 0))

//随机数函数
//long int random(void);
//设置随机种子的函数
//void srandom(unsigned int seed);


//形参为数组名   n为数组元素的个数
//int a[], 数组类型,  可以省略数组的为数
//数组名作为参数的时候，实际上是退化为一个指针
//int array_random(int *a, int n)
int array_random(int a[], int n)
{
    int i = 0;

    //设置随机种子
    srandom(time(NULL));
    printf("sizeof(a):  %d\n", sizeof(a));

    for (i = 0; i < n; i++)
    {
        //获取随机数
        a[i] = random() % 100; 
    }
    return 0;
}

//遍历数组
int array_show(int a[], int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        printf("%d  ", a[i]); 
    }
    //换行
    putchar('\n');
}

int main(void)
{
    int a[10];
    int b[3][4];
    int c[2][3][4][5][6];
    printf("sizeof(a):  %d\n", sizeof(a));

    //函数的调用 后面的参数是实参
    array_random(a, sizeof(a) / sizeof(a[0]));
    //函数的调用  后面的参数是实参
    array_show(a, ARRAY_NUM(a));

    printf("sizeof(b) / sizeof(b[0]):  %d\n", sizeof(b) / sizeof(b[0]));
    printf("sizeof(b) / sizeof(b[0]):  %d\n", ARRAY_NUM(b));
    printf("sizeof(c) / sizeof(c[0]):  %d\n", ARRAY_NUM(c));
    

    return 0;
}
