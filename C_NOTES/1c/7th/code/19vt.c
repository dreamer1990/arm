#include <stdio.h>

//定位光标
int gotoxy(int x, int y)
{
    printf("\033[%d;%dH", x, y);
    return 0;
}

//上移x行
int move_up(int x)
{
    printf("\033[%dA", x);
    return 0;
}

//下移x行
int move_down(int x)
{
    printf("\033[%dB", x);
    return 0;
}

//左移x列
int move_left(int x)
{
    printf("\033[%dD", x);
    return 0;
}


//右移x列
int move_right(int x)
{
    printf("\033[%dC", x);
    return 0;
}

//控制前景和背景输出一个字符
int vt_putchar(int fcolor, int bcolor, char c)
{
    printf("\033[%d;%dm %c \033[0m", fcolor, bcolor, c);
    return 0;
}
//控制前景和背景输出一个字符串
int vt_puts(int fcolor, int bcolor, char *s)
{
    printf("\033[%d;%dm%s\033[0m", fcolor, bcolor, s);
    return 0;
}



int main(void)
{
    vt_putchar(30, 42, 'A');
    putchar('\n');
    vt_puts(37, 45, "Hello uplooking"); 
    putchar('\n');
    printf("\033[3Ihello world");
    fflush(NULL);
    
    return 0;
}
