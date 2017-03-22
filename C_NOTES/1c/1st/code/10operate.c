#include <stdio.h>

/*
 *    
 *    1):基本的算术运算：
 *        +  ：正号运算符(单目运算符)
 *        -  ：负号运算符(单目运算符)
 *        *  ：乘法运算符
 *        /  ：除法运算符
 *        % ：求余运算符
 *        +  ：加法运算符
 *        -  ：减法运算符
 *
 */

int main(void)
{
    int a = 3;
    int b = 4;
    int result;

    // 8赋值给a
    a = +8;
    printf("a = %d  b = %d\n", a, b);

    a = -a;
    printf("a = %d  b = %d\n", a, b);
    
    // * 乘  -8 * 4 = -32;
    result = a * b; 
    printf("result:  %d\n", result);

    //  / 除
    a = 7, b =  -2;
    result = a / b;
    printf("a / b:  %d\n", result);

    // + 加
    result = a + b;
    printf("a + b = %d\n", result);

    //- 减
    result = a - b;
    printf("a - b = %d\n", result);

    // %求模  两个操作数都是整形
    // 错误：双目运算符 % 操作数无效
    //result = a % 1.0;
    result = a % b;
    printf("a % b = %d\n", result);



    return 0;
}
