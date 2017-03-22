#include <stdio.h>

//fun_t是函数指针类型  typedef 别名  typedef是一个关键字
//返回值是int类型  有两个int类型的形参 
typedef int(*fun_t)(int, int);

int min(int x, int y)
{
    return x > y ? y : x;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

int add(int x, int y)
{
    return x + y;
}

//fun_t p; p是一个函数指针变量, 它作为函数的参数
int fun(int x, int y, fun_t p)
{
    return p(x, y);
}

int main(void)
{
    int a = 3;
    int b = 4;
    int choice = 0;

    while(1)
    {
        printf("=======欢迎进入系统==============\n"); 
        printf("1.   max\n");
        printf("2.   min\n");
        printf("3.   add\n");
        printf("4.   quit\n");
        printf("=================================\n");

        scanf("%d", &choice);

        if (4 == choice)
        {
            printf("很遗憾就要离开了，期待下一次愉快的见面\n");
            //退出循环
            break;
        }

        switch(choice)
        {
            case 1:
                printf("最大的数是:  %d\n", fun(a, b, max));
                break;
            case 2:
                printf("最小的数是:  %d\n", fun(a, b, min));
                break;
            case 3:
                printf("两个数相加:  %d\n", fun(a, b, add));
                break;
            case 4:
                printf("很遗憾就要离开了，期待下一次愉快的见面\n");
                break;
            default:
                printf("方式不对, 请重新选择...\n");
        }
    }


    return 0;
}
