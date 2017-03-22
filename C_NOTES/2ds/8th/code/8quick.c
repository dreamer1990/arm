#include <stdio.h>
#include <stdlib.h>

#define SIZE 10


/*
 * swap - swap value of @a and @b
 */
#define swap(a, b) \
    do { typeof(a) __tmp = (a); (a) = (b); (b) = __tmp; } while (0)


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

//找到枢轴
int partion(int *a, int low, int high)
{
    //a[low]值作为枢轴  枢轴左边的数字都比它小 右边的数字都比它大
    int privot = a[low]; 

    while(low < high)
    {
        
        //等于号不能少
        //从后面往前找一个比枢轴小的数字 并且交换
        while(low < high && privot <= a[high]) 
            high--;
        //将小的数字交换到数轴左边
        swap(a[low], a[high]);

        //从前往后找一个比枢轴大的数字 交换到右边去
        while(low < high && a[low] <= privot)
            low++;
        swap(a[low], a[high]);
    }

    //循环条件结束  low==high

    return low;
}

//快速排序算法
void quick_sort(int *a, int low, int high)
{
    int mid = partion(a, low, high);

    printf("mid = %d\n", mid);
    
    if (low >= high)
        return;
    
    quick_sort(a, low, mid - 1);
    quick_sort(a, mid + 1, high);
}



int main(void)
{
    int a[SIZE] = {0};

    array_random(a, SIZE);
    array_show(a, SIZE);

    quick_sort(a, 0, SIZE - 1);
    array_show(a, SIZE);


    return 0;
}







