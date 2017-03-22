#include <stdio.h>


//前提条件是选中要注释的块
//,cs 快速注释
//,cu 快速取消注释

/*
 *1. 用户输入学生的成绩, 
 *    90分以上   printf("Rank A\n");
 *    80分以上                B
 *    70                      C
 *    60                      D
 *    other                   E
 */

int main(void)
{
    //定义score的时候初始化为0
    int score = 0;

    printf("please input a number:    \n");
    scanf("%d", &score);

    if (score >= 90)
    {
        //即使只有一个语句 也建议加上{}
        printf("Rank A\n"); 
    }
    else if (score >= 80)
    {
        printf("Rank B\n"); 
    }
    else if (score >= 70)
    {
        printf("Rank C\n"); 
    }
    else if (score >= 60)
    {
        printf("Rank D\n"); 
    }
    else
    {
        printf("Rank E\n");
    }

    return 0;
}

