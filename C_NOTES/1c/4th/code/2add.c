#include <stdio.h>


//函数的声明
//函数的声明可以声明多次
int sub(int x, int y);
int sub(int x, int y);
int sub(int x, int y);

/*
 *    b. 定义有参函数:
 *    类型名 函数名（形式参数表列）
 *    {
 *       函数体
 *    }
 */


/*
 *    c. 定义空函数
 *    类型名 函数名()
 *    {
 *    }
 */


/*
 *    用空函数占一个位置，以后逐步扩充
 *    好处：程序结构清楚，可读性好，以后扩充新功能方便，对程序结构影响不大
 */
int add_v1(void)
{
    //函数体为空
    return 0;
}

//函数的返回值为int   函数的形参为x 和y, 类型都为int
int add(int x, int y)   //add函数头
{                       //函数体开始
    return x + y;       //函数体
}                       //函数体结束

int sub(int x, int y)
{
    //如果有多个返回值, 则遇到第一个return语句就返回，后面的return语句不执行。
    //如果返回值与函数定义的返回值不一致，则以函数定义的返回值为准
    return 3.14;  //返回3
    return x - y;
    return x;
    return y;
}


int main(void)
{
    int a = 3;
    int b = 4;
    int c = 0;

    //函数的调用 这里的a和b 是实参
    //函数表达式
    c = add(a, b);

    printf("a + b = %d\n", c);

    //函数的返回值作为一个函数的参数
    c = add(a, add(a, b));
    printf("a + a + b = %d\n", c);

    return 0;
}
