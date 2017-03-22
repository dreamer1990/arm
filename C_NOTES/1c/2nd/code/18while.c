#include <stdio.h>

/*
 *第一个种方式
 *while(条件)
 *{
 *    语句
 *}
 */

int main(void)
{
    int i = 1;
    int sum = 0;

    //如果i < 101 成立，则执行循环体，否则退出循环
    while(i < 101)
    {
        //累加和
        sum = sum + i; 
        //i++;  // i = i + 1;  // i += 1;
        //改变循环变量的值, 否则循环不会结束
        ++i;
    }

    printf("1 + 2 + 3 + ... + 100 = %d\n", sum);
    return 0;
}
