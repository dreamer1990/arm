#include <stdio.h>


int main(void)
{
    int a = 3;
    int b = 4;

    //短路规则

    // 如果 条件成立 就输出1  否则输出0
    printf("a >= b && a <= b: %d\n", a >= b && a <= b);

    //如果 a >= b 不成立 则&&后面的表达式不用判断
    a >= b && printf("hello world aaaa\n"), a <= b;
        
    //如果 a <= b 成立 则要判断&&后面的表达式
    a <= b && printf("hello world bbbb\n"), a <= b;

    //逻辑或
    //如果 a <= b不成立则会判断后面表达式
    a <= b || printf("hahhahhah  aaaaaaaa\n");
    //如果 a >= b 成立就不会判断后面的表达式
    a >= b || printf("hahhahah  bbbbbbbbb\n");

    return 0;
}
