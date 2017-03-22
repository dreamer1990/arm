#include <stdio.h>

int main(void)
{
    int a[10];
    int i;

    //循环给每个数组赋值
    for (i = 0; i < 10; i++)
    {
        a[i] = i + 1; 
    }

    //循环输出数组中每一个元素
    for (i = 0; i < 10; i++)
    {
        printf("%d  ", a[i]); 
    }
    putchar('\n');



    return 0;
}
