#include <stdio.h>

int main(void)
{
    int a = 3;
    int b = 4;
    int tmp = 0;


    printf("a = %d  b =  %d\n", a, b);
    //交换的第一种方法,借助第3个变量
    tmp = a;
    a = b;
    b = tmp;

    printf("a = %d  b =  %d\n", a, b);

    //交换的第二种方法 可能会出现溢出
    a = a + b; // a = 3 + 4;
    b = a - b; // b = 7 - 4 = 3;
    a = a - b; // a = 7 - 3 = 4;
    printf("a = %d  b = %d\n", a, b);

    //第三种  异或实现
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("a = %d  b = %d\n", a, b);

    return 0;
}
