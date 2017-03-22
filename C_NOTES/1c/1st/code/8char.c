#include <stdio.h>

/*
 *
 *    6):字符类型
 *        字符是按其代码(整数)形式存储的，C99把字符型数据作为整数类型的一种，字符型数据在使用上有自己的特点。
 *
 *        字母：A ~Z，a ~z
 *        数字：0～9
 *        专门符号：29个：!  ”  #  &  ‘  (  )  *等
 *        空格符：空格、水平制表符、换行等
 *        不能显示的字符：空(null)字符(以‘\0’表示)、警告(以‘\a’表示)、退格(以‘\b’表示)、回车(以‘\r’表示)等
 *
 */

// printf %c输出一个字符
int main(void)
{
    char ch;

    ch = 'A';
    printf("ch = %c\n", ch);

    ch = 65; //与ch = 'A'等价
    printf("ch = %c\n", ch);
    // “A” 与 'A'是有区别  
    // 'A' 是一个字符
    // "A" 是一个字符串常量 sizeof("A") --> 2
    //ch = "A";  //错误的写法 不能用双引号
    
    //数字字符
    ch = '9';
    //%d 输出字符9的ascii  '9'代表字符9
    printf("ch = %c ch = %d\n",ch, ch);

    //特殊字符  \n代表转义 换行
    // \" 转义“
    printf("\"\"\n");
    //字符串有自动粘贴的功能
    printf("hello" "  world\n");

    //打印%% 打印一个%   (n + 1) / 2
    printf("%%%%%\n");

    // \符号
    //printf("\\n"); // 输出\n
    printf("\\\n"); // 输出\n


    return 0;
}
