#include <stdio.h>


/*
 *    带参数的宏和函数的区别:
 *(1) 函数调用时，先求出实参表达式的值，然后代入形参。而使用带参的宏只是进行简单的字符替换。
 *(2) 函数调用是在程序运行时处理的，为形参分配临时的内存单元。而宏展开则是在编译前进行的，在展开时并不分配内存单元，不进行值的传递处理，也没有“返回值”的概念。
 *(3) 对函数中的实参和形参类型要求一致。而宏名无类型，它的参数也无类型，只是一个符号代表，展开时代入指定的字符串即可。宏定义时，字符串可以是任何类型的数据。
 *(4) 调用函数只可得到一个返回值，而用宏可以设法得到几个结果。 
 *(5) 使用宏次数多时，宏展开后源程序长，因为每展开一次都使程序增长，而函数调用不会使源程序变长。
 *(6) 宏替换不占运行时间，只占编译时间。而函数调用则占运行时间（分配单元、保留现场、值传递、返回）。
 *
 */

//返回最大值的宏 只占用编译时间 不占用运行时间
#define MAX(a, b) ((a) > (b) ? (a) : (b))
//返回最大值的函数 占用运行时间
int max(int x, int y)
{
    return x > y ? x : y;
}

int main(void)
{
    int a = 3;
    int b = 100;
    printf(" max = %d\n", max(a, b));

    printf("max = %d\n", MAX(a, b));
    printf("max = %d\n", MAX(a, b));
    printf("max = %d\n", MAX(a, b));
    printf("max = %d\n", MAX(a, b));
    printf("max = %d\n", MAX(a, b));
    printf("max = %d\n", MAX(a, b));

    return 0;
}