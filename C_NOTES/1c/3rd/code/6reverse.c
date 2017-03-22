#include <stdio.h>

int main(void)
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i = 0;

    //正向输出数组中元素
    for (i = 0; i < 10; i++)
    {
        printf("%d  ", a[i]); 
    }
    putchar('\n');

    //逆向输出数组中元素
    for (i = 9; i >= 0; i--)
    {
        printf("%d  ", a[i]); 
    }
    putchar('\n');


    return 0;
}
