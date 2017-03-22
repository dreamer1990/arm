#include <stdio.h>

//数组指针与指针数组的区别

int main(void)
{
    int i, j;
    int a[2][3] = {1, 2, 3, 4, 5, 6};

    //数组指针: 指向数组的指针
    int (*p)[3] = NULL;

    //指针数组: 数组中每一个元素都是指针类型
    int *p1[3];


    p = a;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++) 
        {
            //p[i][j]与*(*(p + i) + j)是等价
            //printf("%2d  ", *(*(p + i) + j)); 
            printf("%2d  ", p[i][j]);
        }
        putchar('\n');
    }


    return 0;
}
