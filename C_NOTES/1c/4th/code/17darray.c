#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//求一个数组中元素的个数
#define ARRAY_NUM(a)  (sizeof(a) / sizeof(a[0] + 0))

/*
 *     b. 数组名作函数参数
 *     用数组名作函数实参时，向形参 传递的是数组首元素的地址
 *     c. 多维数组名作函数参数
 */

//给数组元素随机赋值
//二维数组的第二维不能省略，第一维可以省略，编译器不做第一维检查
//第一维的大小通过参数传进来
//int array_random(int a[100][5], int n);
int array_random(int a[][5], int n)
{
    int i, j;

    //设置随机种子
    srandom(time(NULL));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 5; j++) 
        {
            //获取随机数
            a[i][j] = random() % 100; 
        }
    }
}

int array_show(int a[][5], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 5; j++) 
        {
            printf("%2d  ", a[i][j]);
        }

        //换行
        putchar('\n');
    }
}

int main(void)
{

    int a[4][5];

    array_random(a, sizeof(a) / sizeof(a[0]));
    array_show(a, sizeof(a) / sizeof(a[0])); 

    return 0;
}
