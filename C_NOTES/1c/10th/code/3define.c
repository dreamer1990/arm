#include <stdio.h>

#define AA  int a = 3; int b = 4

//简单的宏替换, 预处理的时候进行宏展开
#define  BB printf("hello world\n");     \
            printf("aaaaaaaaaaaaaaaa\n")

//gcc -E file.c -o file.i
int main(void)
{

    AA;

    printf("a = %d  b = %d\n", a, b);

    BB;

    return 0;
}
