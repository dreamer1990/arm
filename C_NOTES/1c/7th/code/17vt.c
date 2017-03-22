#include <stdio.h>
#include <stdlib.h>

//定位光标
int gotoxy(int x, int y)
{
    printf("\033[%d;%dH", x, y);
}

//上移x行
int move_up(int x)
{
    printf("\033[%dA", x);
}

//下移x行
int move_down(int x)
{
    printf("\033[%dB", x);
}

//左移x列
int move_left(int x)
{
    printf("\033[%dD", x);
}

//右移x列
int move_right(int x)
{
    printf("\033[%dC", x);
}

int main(void)
{

    system("clear");
    gotoxy(3, 4);

    printf("aaaaaa\n");

    gotoxy(5, 20);
    printf("hello boy, i am here\n");

    gotoxy(20, 20);
    //printf("A");

    printf("================");
    //刷新标准输出流

    move_up(5);
    printf("A");
    move_down(3);
    printf("B");

    move_left(10);
    printf("D");

    move_right(5);
    printf("C");

    printf("\033[6n");
    
    fflush(stdout);

    while(1)
        ;

    return 0;
}
