#include <stdio.h>

/*
 *    有a个学生，每个学生有b门课程的成绩。要求在用户输入学生序号以后，能输出该学生的全部成绩。用指针函数实现。
 *    float score[ ][4]={{60,70,80,90},{56,89,67,88},{34,78,90,66}}; 
 *
 */


//返回数组指针的函数
//定义数组指针的别名
typedef int(*array_t)[4];

array_t  find_stu(int score[][4], int index)
{
    //以下两句等价
    //return &score[index];
    return score + index;
}
int main(void)
{
    int index;
    int i = 0;
    array_t parr = NULL;
    int score[3][4] = {{60, 70, 80, 90}, {56, 89, 67, 88}, {34, 78, 90, 66}};

    printf("please input a index:   \n");
    scanf("%d", &index);

    if (index >= 3)
    {
        printf("out of ranged....\n"); 
        goto err0;
    }

    //找到对应学生的成绩
    parr = find_stu(score, index);

    //显示学生每门课程的成绩
    for (i = 0; i < 4; i++)
    {
        printf("%2d  ", *(*parr + i)); 
    }
    putchar('\n');

    return 0;
err0:
    return -1;
}
