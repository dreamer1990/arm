#include <stdio.h>

int main(void)
{

    printf("hello world\n");

    //"hello world"本身就代表一个地址,是这个字符串的首地址
    printf("str:  %p\n", "hello world");
    printf("str:  %p\n", "hello world1");

    printf("%c  %c  %c \n", *"hello", *("hello" + 1), *("hello" + 2));

    printf("%s\n", "hello world" + 6);

    printf("===========================\n");

    //"hello"代表这个字符串的首地址
    printf("%c  %c  %c\n", "hello"[0], "hello"[1], "hello"[2]);


    return 0;
}
