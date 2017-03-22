#include <stdio.h>

/*
 *如果expr1条件为真  expr2, 如果expr1为假， expr3
 *expr1 ? expr2 : expr3;
 *
 */
int main(void)
{
    int a = 3;
    int b = 5;
    unsigned c = 3;

    // a > b 条件为真  a
    // a > b 条件为假  b
    // C语言中唯一一个三目运算符
    a = a > b ? a : b;
    printf("max :  %d\n", a);

    a = -4;

    //隐式转换  int ---> unsigned
    c + a > 0 ? printf("Yes\n"): printf("NO\n");

    a + b > -1 ? printf("a + b > -1\n"): printf("a + b <= -1\n");

    return 0;
}
