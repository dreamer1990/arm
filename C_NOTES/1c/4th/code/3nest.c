#include <stdio.h>

//函数add的声明
int add(int x, int y);

//函数add3的定义
int add3(int x, int y, int z)
{
    int tmp;
    //嵌套调用add函数
    tmp = add(x, y) + z;

    //函数可以嵌套调用，但是不可以嵌套定义
/*
 *    int add4(void)
 *    {
 *        printf("hello world..\n");
 *        return 0; 
 *    }
 */
    return tmp;
}

int main(void)
{
    add(1, 2);
    printf("a + b + c = %d\n", add3(1, 2, 3));
    
    return 0;
}


int add(int x, int y)
{
    int z = x + y;
    return z;  //z的类型应该与函数的返回值一致，如果不一致就隐式的转换
}

