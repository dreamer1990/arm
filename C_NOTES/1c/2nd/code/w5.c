#include <stdio.h>

//打印九九乘法表

int main(void)
{
    int i, j;

    //控制多少行
    for (i = 1; i < 10; i++)
    {
        //控制每一行的输出
        for (j = 1; j<= i; j++)
        {
            printf("%d*%d=%2d ", j, i, i * j); 
        }
        putchar('\n');
    }

    return 0;
}
