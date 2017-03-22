#ifndef __VT_H__
#define __VT_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

void gotoxy(int x, int y);//定位
void putch(int fcolor, int bcolor, int ch);//字符
void putstr(int fcolor, int bcolor, char *s);//字符串
void show_cur(void);//显示光标
void hide_cur(void);//隐藏光标
void save_cur(void);//保存光标
void load_cur(void);//加载光标
void move_left(int step);//左移
void move_right(int step);//右移
void move_up(int step);//上移
void move_down(int step);//下移
void draw_vline(int x, int y, int len, int color, int ch);//竖线
void draw_hline(int x, int y, int len, int color, int ch);//横向
void draw_rect(int x, int y, int w, int h, int color, int ch);//实体盒子
void draw_box(int x, int y, int w, int h, int color, int ch);//空体盒子

#endif /*VT_H*/
