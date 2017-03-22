#include <stdio.h>

/*
 *    long ftell(FILE *stream);
 *    功能:返回当前文件位置标记的位置
 *    参数:
 *        stream: 文件指针
 *    返回值:
 *        返回当前文件位置标记的位置
 *
 *    void rewind(FILE *stream);
 *    功能:将当前文件位置标记指向文件的开头
 *    参数:
 *        stream: 文件指针
 *    返回值: 
 *        void
 *
 */


int main(void)
{
    FILE *fp = NULL;

    int ret = 0;

    fp = fopen("txt", "w+");
    if (NULL == fp)
    {
        printf("fopen file error...\n"); 
        goto err0;
    }
    //0  以读写的方式打开文件,文件位置标记指向文件的开头
    printf("current position:  %d\n", ftell(fp));
    //该操作会使文件位置标记发生改变 
    fputs("hello", fp);
    // 5
    printf("current position:  %d\n", ftell(fp));

    //将文件位置标记指向文件开头的地方
    rewind(fp);
    printf("current position:  %d\n", ftell(fp));
    
    //将会文件部分内容覆盖
    fputs("aaaaa bbbbb", fp);
    printf("current position:  %d\n", ftell(fp));


    fclose(fp);
    return 0;
err0:
    return -1;
}
