#include <stdio.h>
/*
 *#ifndef EOF
 *# define EOF (-1)
 *#endif
 */

int main(void)
{
    char buf[32];

    //可以输入空格  \t 遇到换行就输入结束
    //warning: the `gets' function is dangerous and should not be used.
    gets(buf);

    //将字符串输出到标准输出
    puts(buf);


    return 0;
}
