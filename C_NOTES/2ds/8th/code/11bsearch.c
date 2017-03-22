#include <stdio.h>
#include <stdlib.h>

#define SIZE 20


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


int my_cmp(const void *a, const void *b)
{
    return *(int*)a > *(int *)b;
}


int main(void)
{
    int n;
    int *p = NULL;
    int a[SIZE] = {0};

    array_random(a, SIZE);
    array_show(a, SIZE);
    
    printf("please input a key:  ");
    scanf("%d", &n);

    qsort(a, SIZE, sizeof(int), my_cmp);
     
    p = bsearch(&n, a, SIZE, sizeof(int), my_cmp);
    printf("*p = %d\n", *(int*)p);

    return 0;
}







