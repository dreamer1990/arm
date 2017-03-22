#include <stdio.h>

/*
 *2. 使用fgetc fputc feof实现一个文件拷贝
 *
 *    拷贝文件file1的内容到文件file2中去
 *
 *    int main(int argc, char **argv)
 *    ./a.out file1  file2
 *
 */

int main(int argc, char **argv)
{
    FILE *fin = NULL, *fout = NULL;
    int ch;
    
    printf("argc = %d\n", argc);
    if (argc < 3)
    {
        printf("usage: ./a.out filename1  filename2\n"); 
        goto err0;
    }

    //打开文件file1
    fin = fopen(argv[1], "r");
    if (NULL == fin)
    {
        printf("fopen file1 failed...\n"); 
        goto err0;
    }

    //打开文件file2
    fout= fopen(argv[2], "w");
    if (NULL == fout)
    {
        printf("fopen file2 failed...\n"); 
        goto err0;
    }
    
    //将file1的内容拷贝到file2中
    while(!feof(fin))
    {
        ch = fgetc(fin); 
        if (-1 == ch)
            break;
        fputc(ch, fout);
    }

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
