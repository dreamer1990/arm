#include <stdio.h>


/*
 *    (8) 用指针变量指向一个格式字符串，可以用它代替printf函数中的格式字符串。
 *    char *format;
 *    format=”a=%d,b=%f\n”; 
 *    printf(format,a,b);
 *    相当于
 *    printf(“a=%d,b=%f\n”,a,b);
 *    
 */


int main(void)
{
    int a = 3;
    int b = 4;

    char *s = "a = %d  b = %d\n";
    char *s1 = "hello world  ";
    char *s2 = "Hello WORLD";


    printf(s, a, b);
    //字符串有自动粘贴的功能
    printf("hello " "world\n");
    printf("==================\n");

    //只输出了hello
    printf("hello\n", "world\n");

    return 0;
}
