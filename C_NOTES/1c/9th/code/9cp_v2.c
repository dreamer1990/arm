#include <stdio.h>

#define SIZE 32

//usage: ./a.out file1 file2
int main(int argc, char **argv)
{
    FILE *fin = NULL, *fout = NULL;
    char buf[SIZE];
    char *p;

    if (argc < 3)
    {
        printf("usage: ./a.out filename1 filename2\n"); 
        goto err0;
    }

    //以只读的方式打开一个文件
    fin = fopen(argv[1], "r");
    if (NULL == fin)
    {
        printf("fopen file failed...\n"); 
        goto err0;
    }
    //以只写的方式打开一个文件
    fout = fopen(argv[2], "w");
    if (NULL == fout)
    {
        printf("fopen file failed..\n"); 
        goto err0;
    }

    while(!feof(fin))
    {
        //从fin中读取字符串保存到buf中
        p = fgets(buf, SIZE, fin); 
        if (NULL == p)
           break;
        //将buf中的字符串写入fout流中
        fputs(buf, fout);
    }

    //关闭文件
    fclose(fin);
    fclose(fout);
    return 0;
err0:
    if (NULL != fin)
        fclose(fin);
    if (NULL != fout)
        fclose(fout);
    return -1;
}
