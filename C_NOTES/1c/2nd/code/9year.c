#include <stdio.h>

/*
 *3. 用户输入一个int类型的数字,判断该年是否为闰年
 *    year
 *    a. 能被4整除不能被100整除
 *    b. 能够被400整除的
 *
 *    如果year是闰年
 *        printf("%d is a leap year\n");
 *    如果year不是闰年
 *        printf("%d is not a leap year\n");
 */

int main(void)
{
    int year;
    char flag = 0;
    int ret;
    printf("please input a year:    \n");
    scanf("%d", &year);
    //ret = scanf("%d", &year);
    //printf("ret : %d\n", ret);
    
    /* 不可以嵌套的*/
    #if 0
    /*
     */*this is a comment2*/
     *this is a comment1 
     */
    #endif

    #if 0
    //if语句的嵌套
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                flag = 1;
            }
            else  //跟最近的一个没有配对的if匹配
            {
                flag = 0;
            }
        }
        else
        {
            flag = 1; 
        }
    }
    else
    {
        flag = 0; 
    }

    if (flag == 0) 
        printf("%d is not a leap year\n", year);
    else
        printf("%d is a leap year..\n", year);
    #else

        if (year % 4 == 0 && year % 100 != 0 ||  year % 400 == 0)
            printf("%d is a leap year..\n", year);
        else
            printf("%d is not a leap year...\n", year);
    #endif
    return 0;
}
