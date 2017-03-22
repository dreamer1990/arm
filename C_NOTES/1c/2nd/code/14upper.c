#include <stdio.h>

/*
 *4. 用户输入一个字符, 如果为小写的字母，则转换为大写的输出,其他按原样输出
 *    用三目运算符
 *    'a' - 32 
 *    'a' - ('a' - 'A')
 *    printf("%c\n", ch);
 */

int main(void)
{

    char ch;

    //获取一个字符
    ch = getchar();

    // 小写字母的判断条件: ch >= 'a' && ch <= 'z'
    ch = ch >= 'a' && ch <= 'z' ? ch - 32 : ch;

    printf("ch  =   %c\n", ch);

    return 0;
}
