#include <stdio.h>


/*
 *    int feof(FILE *stream);
 *    功能: 检测是否到达文件结尾
 *    参数:
 *        stream: 文件流指针
 *    返回值:
 *        如果到达文件结尾,就返回一个非零的值
 *        如果没有达到文件结尾,就返回零
 */

int main(void)
{
    FILE *fp = NULL;
    int ch = 0;

    //1. 以只读的方式打开一个文件
    fp = fopen("txt", "r");
    if (NULL == fp)
    {
        printf("fopen file failed...\n"); 
        goto err0;
    }
    
    //2. 从文件中一次读取一个字符
    while(!feof(fp))
    {
        ch = fgetc(fp); 
        if (-1 == ch)
            break;
        putchar(ch);
    }


    //3. 关闭文件
    fclose(fp);
    return 0;
err0:
    return -1;
}








