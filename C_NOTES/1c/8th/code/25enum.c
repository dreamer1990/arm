#include <stdio.h>

/*
 *说明:
 *(1) C编译对枚举类型的枚举元素按常量处理，故称枚举常量。不要因为它们是标识符(有名字)而把它们看作变量，不能对它们赋值。例如: 
 *     sun=0; mon=1;   错误
 *
 *(2) 每一个枚举元素都代表一个整数，Ｃ语言编译按定义时的顺序默认它们的值为0,1,2,3,4,5…
 *在上面定义中，sun的值为0，mon的值为1,…sat的值为6
 *如果有赋值语句: 
    workday=mon; 
 *  相当于workday=1;
 *
 *也可以人为地指定枚举元素的数值，例如: 
 *enum Weekday{sun=7,mon=1,tue,wed,thu,fri,sat}workday,week_end; 
 *指定枚举常量sun的值为7，mon为1，以后顺序加1，sat为6。
 *
 *(3) 枚举元素可以用来作判断比较。例如： 
 *if(workday==mon)
 *if(workday>sun)
 *枚举元素的比较规则是按其在初始化时指定的整数来进行比较的。
 *如果定义时未人为指定，则按上面的默认规则处理，即第一个枚举元素的值为０，故mon>sun，sat>fri
 *
 */

//          7      8    9    10   100        101  102
enum Week{SUN = 7, MON, TUE, WED, THU = 5, FRI, SAT};
enum End {A = 7, B, C, D, E, F};


int main(void)
{
    //错误：赋值运算中的左值无效
    //MON = 1;
    enum Week week;
    week = SUN;
    printf("SUN:  %d week:  %d\n", SUN, week);
    printf("WED:  %d   THU:  %d  FRI:  %d  SAT:  %d\n", WED, THU, FRI, SAT);

    if (SUN > SAT)
    {
        printf("SUN 比SAT要大..\n"); 
    }
    else
    {
        printf("SUN 比 SAT要小...\n"); 
    }

    if (A == SUN)
    {
        printf("A 与SUN相等....\n"); 
    }


    return 0;
}
