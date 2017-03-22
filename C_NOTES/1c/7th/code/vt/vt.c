#include <stdio.h>

void gotoxy(int x, int y)
{
    printf("\033[%d;%dH", x, y);
}

void putch(int fcolor, int bcolor, int ch)
{
    printf("\033[%d;%dm%c\033[0m", fcolor, bcolor, ch);
}

void putstr(int fcolor, int bcolor, char *s)
{
    printf("\033[%d;%dm%s\033[0m", fcolor, bcolor, s);
}

void show_cur(void)
{
    printf("\033[?25h");
}
void hide_cur(void)
{
    printf("\033[?25l");
}
void save_cur(void)
{
    printf("\033[s");
}
void load_cur(void)
{
    printf("\033[u");
}
void move_left(int step)
{
    printf("\033[%dD", step);
}
void move_right(int step)
{
    printf("\033[%dC", step);
}
void move_up(int step)
{
    printf("\033[%dA", step);
}
void move_down(int step)
{
    printf("\033[%dB", step);
}
void draw_vline(int x, int y, int len, int color, int ch)
{
    int i;
    for (i = 0; i < len; i++)
    {
        gotoxy(x + i, y);  
        putch(color, 10, ch); 
    }
}

void draw_hline(int x, int y, int len, int color, int ch)
{
    int i;
    gotoxy(x, y);  
    for (i = 0; i < len; i++)
    {
        putch(color, 10, ch); 
    }
}

void draw_rect(int x, int y, int w, int h, int color, int ch)
{
    int i, j;

    for (i = 0; i < h; i++)
    {
        gotoxy(x + i, y);
        for (j = 0; j < w; j++) 
        {
            putch(color, 10, ch); 
        }
    }
}

void draw_box(int x, int y, int w, int h, int color, int ch)
{
    int i, j;

    for (i = 0; i < h; i++)
    {
        gotoxy(x + i, y);
        for (j = 0; j < w; j++) 
        {
            if (i == 0 || i == h - 1 || j == 0 || j == w - 1)
                putch(color, 10, ch); 
            else
                putch(color, 10, ' '); 
        }
    }
}

