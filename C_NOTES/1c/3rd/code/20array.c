#include <stdio.h>

int main(void)
{
    int i = 0;
    //将数组中指定的元素初始化,其余的默认为0
    int a[10] = {[1] = 3, [5] = 7, [9] = 10};

    for (i = 0; i < 10; i++)
    {
        printf("%d  ", a[i]); 
    }
    putchar('\n');

    return 0;
}
