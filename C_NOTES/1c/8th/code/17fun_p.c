#include <stdio.h>

//fun_t是函数指针的别名
typedef int(*fun_t)(int, int);

struct stu_t {
    int a;      //函数的第一个参数
    int b;      //函数的第二个参数
    fun_t fun;  //函数指针
};

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

int main(void)
{
    int i = 0;
    char op[3] = "+-*";
    //结构体数组

    //结构体数组,并且初始化
    struct stu_t stu[3] = {
    {
        .a = 3,
        .b = 4,
        .fun = add,
    },
    {
        .a = 5,
        .b = 10,
        .fun = sub,
    },
    {
        .a = 10,
        .b = 20,
        .fun = mul,
    },
    };

    for (i = 0; i < 3; i++)
    {
        //stu[i].fun --> add sub  mul
        //stu[i].a  --> a
        //stu[i].b  --> b
        printf("a %c b = %d\n", op[i], stu[i].fun(stu[i].a, stu[i].b)); 
    }

    return 0;
}
