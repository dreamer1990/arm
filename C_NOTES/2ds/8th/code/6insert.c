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

//插入排序算法
void insert_sort(int *a, int n)
{
    int i, j;
    int tmp;

    //需要寻找插入的位置的元素的下标
    for (i = 1; i < n; i++)
    {
        tmp = a[i];
        for (j = i - 1; j >= 0 && tmp < a[j]; j--) 
        {
            a[j + 1] = a[j]; 
        }

        a[j + 1] = tmp;
    
    }

}



int main(void)
{
    int a[SIZE] = {0};

    array_random(a, SIZE);
    array_show(a, SIZE);
    
    insert_sort(a, SIZE);
    array_show(a, SIZE);


    return 0;
}







