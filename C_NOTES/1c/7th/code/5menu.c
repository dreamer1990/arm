#include <stdio.h>

typedef int(*fun_t)(int, int);

int max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x > y ? y : x;
}

int fun(int x, int y, int z)
{
    z = x + y;
    return z;
}

int main(void)
{

    int choice = 0;

    int a = 33;
    int b = 44;
    
    fun_t pfun = NULL;

    //printf("------>sizeof(max):  %d\n", sizeof(max(a, b)));
    printf("------>sizeof(max):  %d\n", sizeof(*max));
    printf("------>sizeof(fun):  %d\n", sizeof(fun));

    while(1)
    {
        printf("=======================\n");
        printf("please make a choice \n"); 
        printf("1.  1--->max\n");
        printf("2.  2--->min\n");
        printf("3.  -1-->quit\n");
        printf("=======================\n");
        scanf("%d", &choice);

        //退出while(1)循环
        if (-1 == choice)
        {
            printf("很遗憾, 期待下一次见面\n");
            break;
        }

        switch(choice)
        {
            case 1:
                pfun = max;
                printf("max(a, b) ---> %d\n", pfun(a, b));
                break;
            case 2:
                pfun = min;
                printf("min(a, b) ----> %d\n", pfun(a, b));
                break;
            default:
                printf("===========default=============\n");
                ;
        }
    }

    return 0;
}
