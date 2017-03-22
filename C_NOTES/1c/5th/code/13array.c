#include <stdio.h>
#include <stdlib.h>

//数组名作为函数的参数
void array_random(int *arr, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        //与arr[i]等价
        *(arr + i) = random() % 100; 
    }
}

void array_show(int *arr, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%2d  ", *(arr + i));
    }
    putchar('\n');
}


int main(void)
{
    int a[10] = {0};

    srandom(time(NULL));

    array_random(a, 10);
    array_show(a, 10);


    return 0;
}
