#include <stdio.h>


int main(void)
{
    char ch;

    printf("请选择性别 G/g 女孩  B/b 男孩..\n");

    //从标准输入获取一个字符
    ch = getchar();

    switch(ch)
    {
        //如果匹配G 或者g 都执行同一个语句块
        case 'G':
        case 'g':
            printf("A beautifull girl....\n");
            break;
        case 'B':
        case 'b':
            printf("A handsome boy...\n");
            break;
        default:
            printf("error...\n");
    }

    return 0;
}
