#include <stdio.h>

//上面3行相当于声明
int a;
int a;
int a;
//全局变量的生命周期 从定义的地方开始到本文件结束
//局部变量只能在函数中定义的地方开始 到该函数结束的范围内可见
//定义一个全局变量，并且初始化,放在数据段中 data
int a = 3;

//全局变量如果没有初始化,则默认初始化为0
int b;

int add(int a);

int main(void)
{
    //局部变量如果没有初始化，则为随机数
    int c;

    a = 100;
    printf("a = %d\n", a);
    printf("3 + a = %d\n", add(3));

    printf("global b: %d  c:   %d\n", b, c);

    //就近原则,
    //如果局部变量与全局变量同名,则局部变量优先
    int a = 88; //局部变量放在栈中
    printf("a = %d\n", a); //输出的是局部变量a

    return 0;
}


//形参a也是局部变量 它的作用域是该函数中可见
int add(int a)
{
    return a + a;
}


