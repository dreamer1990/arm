#include <stdio.h>
#include <stdlib.h>

#define SIZE 20


//void qsort(void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *)



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

int my_cmp(const void *data1, const void *data2)
{
    return *(int *)data1 > *(int *)data2;
}

int main(void)
{

    int a[SIZE];
    array_random(a, SIZE);
    array_show(a, SIZE);
    
    qsort(a, SIZE, sizeof(int), my_cmp);
    array_show(a, SIZE);

    return 0;
}









