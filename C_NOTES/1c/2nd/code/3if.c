#include <stdio.h>
/*
 *
 *第三种形式
 *满足其中一种条件就执行相应的语句块
 *if (cond1)
 *{
 *    cmd1
 *}
 *else if (cond2)
 *{
 *    cmd2
 *}
 *else if (cond3)
 *{
 *    cmd3
 *}
 *....
 *else
 *{
 *    cmdn
 *}
 */

int main(void)
{
    char ch;  

    printf("please input a character...\n");
    scanf("%c", &ch);

    if (ch == 'T')
    {
        printf("特快专车\n");
    }
    else if (ch == 'G')
    {
        printf("高铁..\n"); 
    }
    else if (ch == 'K')
    {
        printf("普快...\n"); 
    }
    else if (ch == 'C')
    {
        printf("城际列车..\n"); 
    }
    else if (ch == 'Z')
    {
        printf("直快..\n"); 
    }
    else if (ch == 'D')
    {
        printf("和谐号动车..\n"); 
    }
    else 
    {
        printf("其他..\n"); 
    }



    return 0;
}
