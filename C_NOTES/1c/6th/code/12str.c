#include <stdio.h>


int main(void)
{
    char *s = "hello world";
    char str[] = "Hello world";

    //与以下等价
    //char *s = NULL;
    //s = "hello world";
    
    //数组不能整体先定义后赋值
    //char str[32];
    //str = "hello world";
    
    printf("%s\n", s);

    //%s遇到字符串结束标志,就停止输出
    s +=6;
    printf("%s\n", s);

    //段错误
    //*s = 'W';

    //数组中的元素可以改变,因为它是放在栈中
    str[0] = 'h';
    printf(str);
    printf("\n");

    printf("============================\n");
    //s指向数组str  
    s = str;
    printf("%s\n", s);
    //改变的内容在栈中
    *s = 'A';
    printf("%s\n", s);

    //%s输出一个字符串  %c输出一个字符
    //%s输出字符串的话,遇到字符串结束符就停止输出
    printf("%c\n", *s);

    return 0;
}
