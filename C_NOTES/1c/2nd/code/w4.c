#include <stdio.h>

/*
 *8. 用户输入一个int n, 输出n行 每一行n个*  n个#      
 *
 *    n = 4;
 *    ****####
 *    ****####
 *    ****####
 *    ****####
 *    a. 用两层循环
 *
 *    b. 用一层循环
 */

int main(void)
{
    int i, j;
    int n  = 0;

    //控制行
    for (i = 0; i < 4; i++)
    {
        //控制一行的输出 
        for (j = 0; j < 8; j++)
        {
            if (j < 4) 
                putchar('*');
            else
                putchar('#');
        }
        putchar('\n');
    }

    printf("==========================\n");
    //总共输出32个字符
    for (i = 0; i < 32; i++)
    {
        if (i % 8 < 4) 
            putchar('*');
        else 
            putchar('#');
        //控制换行
        if (i % 8 == 7)
            putchar('\n');
    }

    printf("==========================\n");
    printf("please input a number:   \n");
    scanf("%d", &n);

    //控制行
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n * 2; j++)  
        {
            if (j % (2 * n) < n) 
                putchar('*');
            else
                putchar('#');
        }
        putchar('\n');
    }
    printf("==========================\n");

    for (i = 0; i < n * n * 2; i++)
    {
        if (i % (n * 2) < n) 
            putchar('*');
        else
            putchar('#');
        if (i % (n * 2) == 2 * n - 1)
            putchar('\n');
    }

    return 0;
}
