#include <stdio.h>

typedef int (*fun_t)(int, int);
//语法解析的时候，无法解析
//typedef int(*)(int, int)  fun_t1;

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int mul(int x, int y)
{
    return x * y;
}

//返回函数指针的函数   ---->  指针函数  
//这里的指针是指向函数的指针
//choice是一个选择的参数  1-->add 2--> sub  3--> mul
//fun_t option(int choice) 与26, 27行是等价
//int(*option(int choice))(int, int )
int(*option(int choice))(int x, int y)
{
    //p的类型是函数指针类型
    fun_t p = NULL;
    switch(choice)    
    {
        case 1:
            //加
            p = add;
            break;
        case 2:
            //减
            p = sub;
            break;
        case 3:
            //乘
            p = mul;
            break;
        default:
            p = NULL;
    }
    
    //返回函数指针
    return p;
}

int main(void)
{
    int choice;
    int a = 5;
    int b = 10;

    while(1)
    {
        printf("==========欢迎进入无敌计算器===========\n"); 
        printf("1. add\n");
        printf("2. sub\n");
        printf("3. mul\n");
        printf("4. quit\n");
        printf("=======================================\n"); 
    
        scanf("%d", &choice);
        if (4 == choice)
        {
            printf("欢迎下次光临...\n"); 
            //跳出while循环
            break;
        }

        switch(choice)
        {
            case 1:
                //option(choice)  等价于 add
                //option(choice)(a, b) 等价于 add(a, b)
                printf("a + b = %d\n", option(choice)(a, b));
                break;
            case 2:
                //option(choice)(a, b)等价于sub(a, b);
                printf("a - b = %d\n", option(choice)(a, b));
                break;
            case 3:
                printf("a * b = %d\n", option(choice)(a, b));
                break;
            default:
                printf("客官  请换个方式....\n");
        }
    }


    return 0;
}
