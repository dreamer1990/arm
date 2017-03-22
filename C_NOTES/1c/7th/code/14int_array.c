#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//给指针数组分配空间
int array_alloc(int *p[], int size, int count)
{
   int i = 0; 
   for (i = 0; i < count; i++)
   {
        p[i] = malloc(size); 
        if (NULL == p[i])
        {
            goto err0;
        }
   }

    return 0;
err0:
    count = i;
    for (i = 0; i < count; i++)
    {
        free(p[i]); 
    }
    return -1;
}

//给数组随机赋值
int array_random(int *p[], int row, int col)
{
    int i, j;
    //控制行
    for (i = 0; i < row; i++)
    {
        //控制列
        for (j = 0; j < col; j++) 
        {
            *(p[i] + j) = random() % 100;
        }
    }

    return 0;
}

//显示数组中的值
int array_show(int *p[], int row, int col)
{
    int i, j;
    //控制行
    for (i = 0; i < row; i++)
    {
        //控制列
        for (j = 0; j < col; j++) 
        {
            printf("%2d  ", *(p[i] + j)); 
        }
        putchar('\n');
    }
}

int array_free(int *p[], int row)
{
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        free(p[i]); 
    }

    return 0;
}



int main(void)
{
    //a是一个数组  a有4个元素
    //a中每一个元素类型是int *类型
    int *a[4];

    array_alloc(a, 40, 4);
    array_random(a, 4, 10);
    array_show(a, 4, 10);
    
    //释放空间
    array_free(a, 4);

    return 0;
}
