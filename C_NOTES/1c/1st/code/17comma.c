#include <stdio.h>

//逗号表达式

int main(void)
{
    int a = 3;
    int b = 4;


    // a = 3
    a = 3, 4, 5, 6, 7;
    printf("a = %d\n", a);

    //逗号表达式最后一个表达式的值为整个表示的值
    a = (3, 4, 5, "hello", 6, 7);
    printf("a = %d\n", a);

    //一条语句  逗号表达式语句
    a++, b++;

    printf("a = %d  b = %d\n", a, b);

    return 0;
}
