#include <stdio.h>
/*
 *
 *第一种形式
 *if (cond1)
 *    cmd;
 */
//如果cond1 为真 就执行cmd语句

int main(void)
{
    int n;

    printf("please input a number:    \n");
    // 输入的时候 n = 33 
    scanf("n=%d", &n);

    // n > 100 关系表达式 如果有多条语句要执行 要用{}形成语句块
    if (n > 100)
    {
        printf("number is larger than 100\n");
        printf("========end if==============\n");
    }

    printf("end...\n");
    return 0;
}
