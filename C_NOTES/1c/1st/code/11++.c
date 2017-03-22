#include <stdio.h>


/*
 *    
 *    2):自增自减运算符：
 *        作用是使变量的值１或减１
 *        ++i，--i：在使用i之前，先使i的值加（减）1
 *        i++，i--：在使用i之后，使i的值加（减）1
 *
 */

int main(void)
{
    int i = 0;
    int tmp;

    //i++ 先使用i的值 然后i自加
    //++i 先使i自加，然后使用i的值

    //tmp = i++; 与tmp = i; i = i + 1;等价
    //tmp = ++i; 与i = i + 1; tmp = i;等价
    //tmp = i--; 与tmp = i; i = i - 1;等价
    //tmp = --i; 与i = i - 1; tmp = i;等价

    //参数是从右往左传进来的
    printf("%d %d %d\n", i++, i++, i++);

    //与编译器相关 2 4 6 4
    i = 1;
    tmp = i++ + i++;
    // 以上语句与tmp = i + i;  i++; i++;等价
    printf("%d\n", tmp);

    i = 1;
    tmp = ++i + i++;
    printf("%d\n", tmp);

    i = 1;
    //语句 i++; i++; tmp = i + i;
    tmp = ++i + ++i;
    printf("%d\n", tmp);

    i = 1;
    tmp = i++ + ++i;
    printf("%d\n", tmp);

    return 0;
}
