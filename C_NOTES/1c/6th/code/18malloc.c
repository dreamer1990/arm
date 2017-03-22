#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//指针函数: 返回指针的函数
int **test(int row, int col)
{
    int **new = NULL;
    int i, j;

    //分配内存
    new = malloc(row * sizeof(int *));
    if (NULL == new)
    {
        printf("malloc failed...\n"); 
        goto err0;
    }
    for (i = 0; i < row; i++)
    {
        //给每一行分配内存
        *(new + i) = malloc(col * sizeof(int));
        if (NULL == *(new + i))
        {
            goto err1; 
        }
    }
    
    return new;
err1:
    while(i-- >= 0)
    {
        free(*(new + i)); 
    }
    free(new);
err0:
    return NULL;
}

//用二级指针模拟二维数组
int array_random(int **p, int row, int col)
{
    int i, j;
    
    //控制行
    for (i = 0; i < row; i++)
    {
        //控制列
        for (j = 0; j < col; j++) 
        {
            *(*(p + i) + j) = random() % 100;
        }
    }

    return 0;
}

int array_show(int **p, int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)    
        {
            printf("%2d  ", *(*(p + i) + j)); 
        }
        putchar('\n');
    }

    return 0;
}

int main(void)
{
    int **p = NULL;
    int i, j;

    p = test(3, 4);

    //设置随机种子
    srandom(time(NULL)); 

    //给模拟的二维数组随机赋值
    array_random(p, 3, 4);
    //显式模拟的二维数组中各个元素
    array_show(p, 3, 4);

    //释放内存
    for (i = 0; i < 3; i++)
    {
        free(*(p + i)); 
    }

    free(p);
    
    return 0;
}
