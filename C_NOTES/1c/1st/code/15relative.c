#include <stdio.h>

/*
 *
 * 结果0 1
 *15. 关系运算符
 *    >   大于
 *    >=  大于或者或者等于
 *    <   小于
 *    <=  小于或者等于
 *    ==  等于
 *    != 不等于
 *
 */

int main(void)
{
    int a = 3;
    int b = 4;

    //关系表达式的值为0 或者为1  0表示条件不成立  1表示条件成立
    //非零为真  0为假
    printf(" a > b:  %d \n", a > b);
    printf(" a < b:  %d \n", a < b);
    printf("a != b:  %d\n", a != b);

    //a = b = 4;
    b = 4;
    a = b;
    printf("a == b:  %d\n", a == b);

    printf("a <= b:  %d\n", a <= b);
    printf("a >= b:  %d\n", a >= b);

    return 0;
}
