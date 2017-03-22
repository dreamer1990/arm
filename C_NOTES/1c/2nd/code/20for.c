#include <stdio.h>

/*
 *第三种方式:
 *for (expr1; expr2; expr3)
 *{
 *
 *}
 */

int main(void)
{
    int i = 0;
    int sum;
    //如果i < 101成立 则执行循环体
    //sum=0, i=1 这是逗号表达式
    for (sum = 0, i = 1; i < 101; i++)
    {
        sum = sum + i; 
    }
    printf("1+2+3+4...+100 = %d\n", sum);

//goto语句 我们一般不推荐用于循环中, 但是常用结束程序
    i = 1;
    sum = 0;
label:
    sum = sum + i;
    i++;
    if (i <= 100)
        goto label; //转到label标签处开始执行

    printf("1+2+3+4+...+100 = %d\n", sum); 

    return 0;
}
