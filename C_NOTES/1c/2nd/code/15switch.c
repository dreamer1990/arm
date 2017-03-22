#include <stdio.h>

//expr 只能是整形 或者整形表达式(char)
/*
 *switch(expr)
 *{
 *    //如果expr与case后面标记匹配,就会执行相应的语句
 *    case 标记1:
 *        语句1
 *        break;
 *    case 标记2:
 *        语句2
 *        break;
 *    ...
 *    default:
 *        语句n
 *}
 */


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
    int score;
    printf("please input a number:   \n");
    scanf("%d", &score);

    if (score < 0 || score > 100)
    {
        printf("out of range..\n");
        return -1;
    }

    //switch可以用于作菜单
    switch(score / 10)
    {
        // 9 和 10 都执行同一个语句块
        case 10:
        case 9 :
            printf("Rank A\n");
            break; //结束switch语句
        case 8:
            printf("Rank B\n");
            break;
        case 7:
            printf("Rank C\n");
            break;
        case 6:
            printf("Rank D\n");
            break;
        default:
            printf("Randk E\n");
    }

    return 0;
}
