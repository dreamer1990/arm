#include <stdio.h>

//##粘贴功能
#define test(x) test##x

int test1(void)
{
    printf("hello world...\n");
    return 0;
}

int test2(void)
{
    printf("hello uplooking...\n");
    return 0;
}

int main(void)
{
    //test(1) 预处理之后变为test1
    //test1();
    test(1)();

    //test2();
    test(2)();

    return 0;
}
