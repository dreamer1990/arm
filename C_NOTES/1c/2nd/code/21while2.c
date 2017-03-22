#include <stdio.h>

//循环的嵌套
//continue 结束本次循环
//break 结束本层循环

/*
 *1
 *22
 *333
 *4444
 *55555
 */

int main(void)
{
    int i, j;
    int n;
    printf("please input a number[1--9]:   \n");
    scanf("%d", &n);

    //控制行
    for (i = 0; i < n; i++)
    {
        //控制每一行输出
        for (j = 0; j <= i; j++) 
        {
            printf("%d", i + 1); 
        }
        putchar('\n');
    }

    printf("======================\n");

    //控制行
    for (i = 0; i < n; i++)
    {
        if (i == 2)
        {
            continue;  //结束本次循环
        }
        //控制每一行的输出 
        for (j = 0; j <= i; j++)
        {
            printf("%d", i + 1); 
        }
        putchar('\n');
    
    }



    return 0;
}
