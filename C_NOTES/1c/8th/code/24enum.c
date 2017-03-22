#include <stdio.h>


/*
 *9. 枚举
 *
 *如果一个变量只有几种可能的值，则可以定义为枚举类型
 *所谓“枚举”就是指把可能的值一一列举出来，变量的值只限于列举出来的值的范围内
 *
 */


/*
 *声明枚举类型用enum开头。
 *例如：
 *enum Weekday{sun,mon,tue,
 *                              wed,thu,fri,sat};
 *声明了一个枚举类型enum Weekday
 *然后可以用此类型来定义变量
 *enum Weekday  workday,weekend;
 *
 */

//声明枚举类型
// 0 1 2 3 4 5 6
enum Week{SUN, MON, TUE, WED, THU, FRI, SAT};

int main(void)
{
    enum Week week1 = SUN; //0
    enum Week week = WED;  //3
    enum Week week2 = SAT; //6

    printf("week:  %d\n", week);
    printf("week1:  %d\n", week1);
    printf("week2:  %d\n", week2);
    
    return 0;
}
