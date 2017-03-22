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

//选择排序的时间复杂度为O(n^2)
//从小到大排序
//选择排序算法
void select_sort(int *a, int n)
{
    int i, j;
    int tmp = 0;

    //总共要排序n - 1个位置
    for (i = 0; i < n - 1; i++)
    {
        tmp = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[tmp] > a[j]) 
                tmp = j;
        }

        if (i != tmp)
            swap(a[i], a[tmp]);
    }

}



int main(void)
{
    int a[SIZE] = {0};

    array_random(a, SIZE);
    array_show(a, SIZE);
    
    select_sort(a, SIZE);
    array_show(a, SIZE);

    return 0;
}







