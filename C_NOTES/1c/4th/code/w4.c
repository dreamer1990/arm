#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


#define ARR_LEN(a)  sizeof(a) / sizeof(a[0] + 0)

//用户输入n个数字，保存到数组中
void array_input(int a[], int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        printf("please input a number:   "); 
        scanf("%d", &a[i]);
    }
}

//给数组中每一个元素随机赋值
void array_random(int a[], int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        //产生101以内的随机数
        a[i] = random() % 101; 
    }
}

//n数组中元素的个数
void array_show(int a[], int n)
{
    int i = 0;

    //数组的遍历
    for (i = 0; i < n; i++)
    {
        printf("%d  ", a[i]); 
    }
    //换行
    putchar('\n');
}

//求数组中最大的一个元素
int array_max(int a[], int n)
{
    int i = 0;
    int max = a[0];

    for (i = 0; i < n; i++)
    {
        if (max < a[i]) 
            max = a[i];
    }

    return max;
}

//求数组中最小的一个元素
int array_min(int a[], int n)
{
    int i = 0;
    int min = a[0];

    for (i = 1; i < n; i++)
    {
        if (min > a[i]) 
            min = a[i];
    }

    return min;
}

//数组中元素循环左移
void array_left(int a[], int n)
{
    int i = 0;
    int tmp = 0;

    tmp = a[0];

    for (i = 0; i < n - 1; i++)
    {
        a[i] = a[i + 1]; 
    }

    //把原来第一个元素放到数组的最后一个位置上
    //i == n - 1
    a[i] = tmp;
}

//循环移动count位
void array_left_v1(int a[], int n, int count)
{
    int i = 0;
    //循环移动count次
    for (i = 0; i < count; i++)
    {
        array_left(a, n); 
    }
}

//循环右移一位
void array_right(int a[], int n)
{
    int i = 0;
    int tmp = a[n - 1];

    for (i = n - 1; i > 0; i--)
    {
        a[i] = a[i - 1]; 
    }
    //i == 0
    a[i] = tmp;
}

//循环右移count位
void array_right_v1(int a[], int n, int count)
{
    int i = 0;
    for (i = 0; i < count; i++)
    {
        array_right(a, n); 
    }
}


//数组元素的反转
void array_reverse(int a[], int n)
{
    int i = 0;
    int tmp = 0;

    for (i = 0; i < n / 2; i++)
    {
        tmp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = tmp;
    }
}

//数组元素的复制
void array_copy(int a[], int b[], int n)
{
    int i = 0; 
    for (i = 0; i < n; i++)
    {
        b[i] = a[i]; 
    }
}




int main(void)
{
    int a[10] = {0};
    int b[10] = {0};

    //赋值类型不兼容
    //b = a;

    //设置随机种子
    //srandom(time(NULL));
    srandom(getpid());

    array_random(a, 10);
    array_show(a, ARR_LEN(a));

#if 0
    printf("===================\n");
    array_input(a, 10);
    array_show(a, 10);
#endif

    printf("==========max================\n");
    printf("max:  %d\n", array_max(a, 10));

    printf("=========min=================\n");
    printf("min:  %d\n", array_min(a, 10));

    printf("===========shift left===========\n");
    array_left(a, 10);
    array_show(a, 10);

    printf("=========shift left count===========\n");
    array_left_v1(a, 10, 3);
    array_show(a, 10);

    printf("=========shift right==================\n");
    array_right(a, 10);
    array_show(a, 10);

    printf("=============shift right count=================\n");
    array_right_v1(a, 10, 3);
    array_show(a, 10);

    printf("==============array reverse=============\n");
    array_reverse(a, 10);
    array_show(a, 10);

    printf("============array copy=================\n");
    array_copy(a, b, 10);
    array_show(a, 10);
    array_show(b, 10);


    return 0;
}
