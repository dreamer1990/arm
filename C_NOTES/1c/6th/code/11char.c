#include <stdio.h>


/*
 *    a. 字符串的引用方式
 *    字符串是存放在字符数组中的。引用一个字符串，可以用以下两种方法。
 *    (1) 用字符数组存放一个字符串，可以通过数组名和格式声明“%s”输出该字符串，也可以通过数组名和下标引用字符串中一个字符。
 *    (2) 用字符指针变量指向一个字符串常量，通过字符指针变量引用字符串常量。
 *
 */

/*
 * char str1[32]; 
 * char *str;
 * str是一个字符指针变量
 * str1是一个字符数组名,代表字符数组的首地址
 */

int main(void)
{
    //"hello world"字符串常量也是放在只读数据段中
    //str所指向的数组中也存放了hello world字符
    char str[] = "hello world";
    char str1[32];

    //定义一个字符指针
    char *s = NULL;

    printf("str:   %s\n", str);
    printf("str[2] = %c\n", str[2]);

    //字符串常量"Hello world"本身放在只读数据段中
    //s 是一个字符类型的指针变量,存放在栈中
    s = "Hello world\n";
    printf(s);
    //错误：赋值时类型不兼容
    //str1 = "hello world";
    
    //段错误 s所指向的字符串放在只读数据段中
    //*s = 'h';

    return 0;
}
