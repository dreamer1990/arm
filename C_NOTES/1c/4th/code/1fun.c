#include <stdio.h>
/*
 *  函数名的命名规则与变量一样
 *
 *    a. 定义无参函数：
 *    类型名 函数名(void)
 *    {
 *       函数体
 *    }
 */

//void 空类型 如果在参数列表中代表该函数没有参数
//void 空类型 如果作为返回值类型 则代表没有返回值
//无返回值  也没有参数的函数
//作用就是执行一定的操作
void display(void)
{
    printf("******************\n");
    printf("******************\n");
    printf("******************\n");
}

void display_info(void)
{
    printf("Welcom to ShenZhen\n");
}

int main(void)
{

#if 0
    printf("******************\n");
    printf("******************\n");
    printf("******************\n");
    printf("Welcom to ShenZhen\n");
    printf("******************\n");
    printf("******************\n");
    printf("******************\n");
#else
    //无参无返回值函数的调用
    display();
    //函数调用语句
    display_info();
    display();
#endif

    return 0;
}
