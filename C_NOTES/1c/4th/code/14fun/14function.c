#include <stdio.h>

/*
 *12. 内部函数和外部函数
 *    内部函数：
 *    如果一个函数只能被本文件中其他函数所调用，它称为内部函数。
 *    在定义内部函数时，在函数名和函数类型的前面加 static，即:
 *        static 类型名 函数名(形参表)
 *    内部函数又称静态函数，因为它是用 static 声明的
 *    通常把只能由本文件使用的函数和外部变量放在文件的开头，前面都冠以 static 使之局
 *部化，其他文件不能引用
 *    提高了程序的可靠性
 *
 *    外部函数：
 *    如果在定义函数时，在函数首部的最左端加关键字 extern，则此函数是外部函数，可供
 *其他文件调用。
 *    如函数首部可以为
 *        extern int fun (int a, int b)
 *    如果在定义函数时省略 extern，则默认为外部函数
 *
 */


//声明函数的时候可以省略形参名,但是不可以省略形参的类型
extern int sub(int, int);
//错误
//extern int sub();
//定义函数的时候 如果没有指定返回值的类型，则默认为int
extern int mul(int, int);

int main(void)
{
    int a = 3;
    int b = 4;

    //add为其它内部函数,此时提示没有定义该函数
    //printf("a + b = %d\n", add(a, b));
    printf("a - b = %d\n", sub(a, b));

    printf("a * b = %d\n", mul(a, b));

    return 0;
}

