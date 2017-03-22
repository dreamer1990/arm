#include <stdio.h>

/*
 *3. 两个矩阵相加
 *    a[2][3]  b[2][3]
 *    1 2 3      1 2 3
 *    1 2 3      4 5 6
 *    相加之后的结果保存到b[2][3]中
 */

int main(void)
{
    int i, j;
    int a[2][3] = {1, 2, 3, 1, 2, 3};
    int b[2][3] = {{1, 2, 3}, {4, 5, 6}};

    //输出a
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++) 
        {
            printf("%d  ", a[i][j]); 
        }
        putchar('\n');
    }
    printf("====================\n");
    //输出b
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++) 
        {
            printf("%d  ", b[i][j]); 
        }
        putchar('\n');
    }
    printf("====================\n");

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++) 
        {
            b[i][j] += a[i][j]; 
        }
    }

    //输出
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++) 
        {
            printf("%d  ", b[i][j]); 
        }
        putchar('\n');
    }


    return 0;
}
