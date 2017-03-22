#include <stdio.h>
/*
 *
 *putchar:向标准输出输出一个字符
 *   int putchar(int c);
 *getchar:从标准输入获取一个字符
 *    int getchar(void);
 */

int main(void)
{
    char ch;

    char buf[32];

    //获取一个字符
    ch = getchar();

    //输出一个字符
    putchar(ch);

    //清空缓冲区
    while(getchar()!= '\n')
        ;

    gets(buf);

    puts(buf);
    

    return 0;
}
