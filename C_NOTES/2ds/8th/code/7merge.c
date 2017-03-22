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

void merge_array(int *a, int l, int mid, int r);

void merge_sort(int *a, int l, int r)
{
    int mid;

    //递归结束的条件
    if (l >= r)
        return;
    
    mid = (l + r ) >> 1;
    //将数组分为两半
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);

    //合并两边有序的数组
    merge_array(a, l, mid, r);
}

void merge_array(int *a, int l, int mid, int r)
{
    int i, j, k;

    //r - l + 1  就是数组a的元素的个数
    int *tmp = malloc(sizeof(int)  * (r - l + 1));
    
    k = 0;
    //将排序好的两部分合并
    for (i = l, j = mid + 1; i <= mid && j <= r ;)
    {
        if (a[i] > a[j]) 
            tmp[k++] = a[j++];
        else
            tmp[k++] = a[i++];
    }

    //第一部分没有合并完 而第二部分已经合并完了
    if (i <= mid)
    {
        while(i <= mid)
            tmp[k++] = a[i++];
    }
        
    //第二部分没有合并完, 而第一部分已经合并完了
    if (j <= r)
    {
        while(j <= r) 
            tmp[k++] = a[j++];
    }

    //将排序好的元素赋值给a中
    for (i = l; i <= r; i++)
    {
        a[i] = tmp[i - l]; 
    }

}





int main(void)
{
    int a[SIZE] = {0};

    array_random(a, SIZE);
    array_show(a, SIZE);
    
    merge_sort(a, 0, SIZE - 1);
    array_show(a, SIZE);


    return 0;
}







