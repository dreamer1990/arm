#include <stdio.h>


/*
 *    1). 在一个文件内扩展外部变量的作用域
 *    外部变量有效的作用范围只限于定义处到本文件结束。
 *    如果用关键字 extern 对某变量作“外部变量声明” 则可以从“声明”处起，合法地使用该外部变量
 */

//可以多次声明
extern int a;
extern int a;

//不能在多个文件中定义同名的全局变量
//int b = 330;

//声明外部函数, 
//声明的时候可以省略形参名，但是不可以省略形参类型
extern int add(int, int);

extern int sub(int x, int y);
//可以声明一个不存在的函数,但是后面的代码不能调用该函数,否则出现没有定义该函数
extern int mul(int x, int y);

int main(void)
{
    printf("extern a = %d\n", a);

    //调用其他文件定义的函数
    printf("a + b = %d\n", add(1, 2));

    //外部sub被static修饰了,所以此处不能调用 
    //printf("a - b = %d\n", sub(10, 7));

    return 0;
}
