#include <stdio.h>


/*
 *    6. 有一个磁盘文件，内有一些信息。要求第一次将它的内容显示在屏幕上，第二次把它复制到另一文件上。
 *
 */

int main(int argc, char **argv)
{
    FILE *fin = NULL, *fout = NULL;
    char buf[32];
    int ret;

    if (argc < 3)
    {
        printf("usage:  ./a.out filename1 filename2\n"); 
        goto err0;
    }

    //打开文件
    fin = fopen(argv[1], "r");
    if (NULL == fin)
    {
        printf("fopen file error...\n"); 
        goto err0;
    }

    fout = fopen(argv[2], "w");
    if (NULL == fout)
    {
        printf("fopen file error...\n"); 
        goto err0;
    }

   
    //读取文件中的内容，显示在屏幕上
    while(1)
    {
        ret = fread(buf, sizeof(char), 32, fin); 
        if (ret <= 0)
            break;
        fwrite(buf, sizeof(char), ret, stdout);
    }
    printf("current position:  %d\n", ftell(fin));

    //将文件位置指针指向文件开始的地方
    fseek(fin, 0L, SEEK_SET);

    //读取文件中的内容,写入另外一个文件
    while(1)
    {
        ret = fread(buf, sizeof(char), 32, fin); 
        printf("ret = %d\n", ret);
        if (ret <= 0)
            break;
        fwrite(buf, sizeof(char), ret, fout);
    }

    //关闭文件
    fclose(fin);
    fclose(fout);

    return 0;
err0:
    if (fin != NULL)
        fclose(fin);
    if (NULL != fout)
        fclose(fout);

    return -1;
}
