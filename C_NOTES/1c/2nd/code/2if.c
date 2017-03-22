#include <stdio.h>


/*
 *第二种形式
 *if (cond1)
 *{
 *    //如果cond1满足条件 就执行cmd1
 *    cmd1;
 *}
 *else 
 *{
 *    //如果cond1不满足条件 就执行cmd2
 *    cmd2
 *}
 *
 */

int main(void)
{
    int n;
    
    printf("please input a number:   \n");
    scanf("%d", &n);

    // n > 0 是关系表达式
    if (n > 0)
    {
        printf(" number is larger than zero\n"); 
    }
    else
    {
        printf("number is less than zero\n"); 
    }


    return 0;
}





