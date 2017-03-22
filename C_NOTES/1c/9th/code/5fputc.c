#include <stdio.h>

/*
 *    int fputc(int c, FILE *stream);
 *    功能:向文件流中输出一个字符
 *    参数:
 *        stream: 文件指针
 *    返回值:
 *        成功: 返回写入的字符
 *        失败: 返回EOF
 *
 */

int main(void)
{
    FILE *fp = NULL;
    char ch = 0;

    //1. 打开文件  只写的方式
    fp = fopen("txt", "w");
    if (NULL == fp)
    {
        printf("fopen file failed...\n"); 
        goto err0;
    }

    while(1)
    {
        //从终端获取一个字符
        ch = getchar(); 
        //遇到q退出
        if (ch == 'q')
            break;
        //向文件流写入一个字符
        fputc(ch, fp);
    }
    //关闭文件
    fclose(fp);
    return 0;
err0:
    return -1;
}
