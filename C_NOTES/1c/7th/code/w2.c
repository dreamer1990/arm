#include <stdio.h>

/*
 *    有a个学生，每个学生有b门课程的成绩。要求在用户输入学生序号以后，能输出该学生的全部成绩。用指针函数实现。
 *    float score[ ][4]={{60,70,80,90},{56,89,67,88},{34,78,90,66}}; 
 *
 */

//找出有一门成绩不合格的学生

//返回数组指针的函数
//定义数组指针的别名
typedef int(*array_t)[4];

array_t  find_stu(int score[][4], int index)
{
    //以下两句等价
    //return &score[index];
    return score + index;
}

//找到只要有一门课程不及格的学生
array_t find_score(int score[][4], int index)
{
    int i = 0;

    //定义指向数组的指针变量
    array_t tmp = NULL;
    tmp = score + index;

    for (i = 0; i < 4; i++)
    {
        if (score[index][i] < 60) 
        {
            break;
        }
    }

    if (i >= 4)
    {
        goto err0; 
    }

    return tmp;
err0:
    return NULL;
}

int main(void)
{
    int index;
    int i = 0;

    array_t parr = NULL;
    int score[3][4] = {{60, 70, 80, 90}, {56, 89, 67, 88}, {34, 78, 90, 66}};

    for (i = 0; i < 3; i++)
    {
        parr = find_score(score, i);
        if(NULL != parr)
        {
            printf("学号为:  %d\n", i);
            for (index = 0; index < 4; index++)        
            {
                printf("%2d  ", *(*parr + index)); 
            }
            printf("\n=========================\n");
        }
    }

    return 0;
}
