#include <stdio.h>


int main(void)
{
    char ch;
    
    printf("please input a character..\n", ch);
    scanf("%c", &ch);

    // 小写字母
    if (ch >= 'a' && ch <= 'z')
        printf("%c is a lower character.\n", ch);
    //大写字母
    else if (ch >= 'A' &&  ch <= 'Z')
        printf("%c is a upper character..\n", ch);
    //数字
    else if (ch >= '0' && ch <= '9')
        printf("%c is a digit number..\n", ch);
    //其他
    else 
        printf("%c is other character..\n", ch);

    return 0;
}
