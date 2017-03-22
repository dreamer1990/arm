#include <stdio.h>
#include <stdlib.h>

#define SIZE 10


/*
 * swap - swap value of @a and @b
 */
#define swap(a, b) \
	do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)


//从小到大排序
//交换排序  不属于正宗的冒泡排序
void bubble_sort_v1(int *a, int n)
{
    int  i, j;

    //循环比较次数
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j]) 
                swap(a[i], a[j]);
        }
    }
}

//从底端开始 小的数字往上浮
//冒泡排序
void bubble_sort_v2(int *a, int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--) 
        {
            if (a[j - 1] > a[j])
                swap(a[j - 1], a[j]);
        }
    }

}

//从顶端开始  大的数往下沉
//冒泡排序
void bubble_sort_v3(int *a, int n)
{
    int i, j;
    //排序多少趟
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++) 
        {
            if (a[j] > a[j + 1]) 
                swap(a[j], a[j + 1]);
        }
    }
}

//改进的冒泡排序算法
void bubble_sort_v4(int *a, int n)
{
    int i, j;
    int flag = 1;   //标记

    
    for (i = 0; flag && i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++) 
        {
            if (a[j] > a[j + 1]) 
            {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
    
    }

}



//给数组中的元素随机赋值
void array_random(int *a, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        *(a + i)  = random() % 100;
    }
}

//输出数组中的元素
void array_show(int *a, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%2d  ", *(a + i)); 
    }
    //换行
    putchar('\n');
}




int main(void)
{
    int a[SIZE] = {0};

    array_random(a, SIZE);
    array_show(a, SIZE);
    
#if 0
    bubble_sort_v1(a, SIZE);
    array_show(a, SIZE);
#endif

#if 0
    bubble_sort_v2(a, SIZE);
    array_show(a, SIZE);
#endif
    
#if 0
    bubble_sort_v3(a, SIZE);
    array_show(a, SIZE);
#endif
    
    bubble_sort_v4(a, SIZE);
    array_show(a, SIZE);

    return 0;
}







