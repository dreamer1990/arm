#include <stdio.h>

//逻辑与 &&
//逻辑或 ||
//逻辑非 !


int main(void)
{
    int score;
    int age;
    printf("please input a number:   \n");
    scanf("%d %d", &score, &age);

    //逻辑或 只要有一个条件成立 整个表达式就为真
    if (score < 0 || score > 100)
    {
        printf("The score is out of range\n"); 
    }

    /*
     *    判断年龄在13至17岁之内？
     *        age >= 13 && age <= 17
     */
    if (age >= 13 && age <= 17)
    {
        printf("年龄在13至17岁之间\n"); 
    }
        return 0;
}
