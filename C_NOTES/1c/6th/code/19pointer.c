#include <stdio.h>
#include <stdlib.h>

void array_random(int (*p)[4], int row)
{
    int i, j;
    //控制行
    for (i = 0; i < row; i++)
    {
        //控制列
        for (j = 0; j < 4; j++)
        {
            *(*(p + i) + j) = random() % 100;
        }
    }
}

void array_show(int (*p)[4], int row)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < 4; j++)    
        {
            printf("%2d  ", *(*(p + i) + j)); 
        }
        putchar('\n');
    }
}

//另外一种方法模拟二维数组
int main(void)
{
    //数组指针: 指向数组的指针
    int (*p)[4] = NULL;
    int i, j;

    p = malloc(3 * 4 * sizeof(int));
    if (NULL == p)
    {
        printf("mallco failed..\n");
        goto err0;
    }

    array_random(p, 3);
    array_show(p, 3);

    free(p);
    return 0;
err0:
    return -1;
}
