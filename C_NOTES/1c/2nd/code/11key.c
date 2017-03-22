#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ch;

    //system 执行shell命令
    //system("ls -l");
    system("stty -echo");  //关闭回显
    system("stty -icanon");//关闭输入缓冲区

    //从标准输入获取一个字符
    ch = getchar();

    if (ch == 'A' || ch == 'a' )
        printf("向左..\n");
    else if (ch == 'D' || ch == 'd')
        printf("向右...\n");
    else if (ch == 'W' || ch == 'w')
        printf("向上....\n");
    else if (ch == 'S' || ch == 's')
        printf("向下...\n");
    else
        printf("方向不对，请重新选择...\n");

    system("stty echo");  //取消关闭回显
    system("stty icanon");//取消关闭输入缓冲区

    return 0;
}

