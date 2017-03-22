#include <stdio.h>


/*
 *    b. 带参数的宏定义
 *    作用：不是进行简单的字符串替换，还要进行参数替换。 
 *    
 *    带参数的宏定义一般形式为:
 *
 *    #define 宏名（参数表）  字符串 
 *        字符串中包含在括弧中所指定的参数
 *
 *    说明：
 *    (1)对带参数的宏展开只是将语句中的宏名后面括号内的实参字符串代替#define 命令行中的形参。
 *    (2) 在宏定义时，在宏名与带参数的括弧之间不应加空格，否则将空格以后的字符都作为替代字符串的一部分。 
 *
 */

//代参数的宏
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define PI 3.1415926535

//S(r)与S1(r)对比
#define S(r) PI * r * r
//括弧之间不应该加空格,否则将空格以后的所有字符都作为替代字符串的一部分
#define S1(r) PI * (r) * (r)

int main(void)
{
    int a = 3;
    int b = 4;

    printf("max = %d\n", MAX(a, b));

    printf("max = %d\n", MAX(a, b) + 1);

    //有时候防止得到不是预期的结果,一般加上括号
    // PI * a + b * a + b
    printf("area:  %lf\n", S(a + b));

    printf("area: %lf\n", S1(a + b));

    return 0;
}



