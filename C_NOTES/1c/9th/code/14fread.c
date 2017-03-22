#include <stdio.h>


/*
 *
 *    size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
 *    功能: 从stream文件流中读取nmemb个元素,每个元素size个字节, 保存到ptr所指向空间中
 *    参数:
 *        ptr:对fread来说，它是用来存放从文件读入的数据的存储区的地址
 *        size:每个元素的大小
 *        nmemb: 读取多少个元素
 *        stream: 文件指针流
 *    返回值:
 *        成功: 返回读了多少个元素
 *        失败: 0
 *
 *    size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
 *    功能: 向stream文件流中写nmemb个元素,每个元素size个字节,从ptr所指向的buf中读取
 *    参数;
 *        ptr:对fwrite来说，是要把此地址开始的存储区中的数据向文件输出
 *        size:每个元素的大小
 *        nmemb: 读取多少个元素
 *        stream: 文件指针流
 *    返回值:
 *        成功: 返回写了多少个元素
 *        失败: 0
 *
 */


int main(int argc, char **argv)
{
    FILE *fin = NULL, *fout = NULL;
    char buf[32];
    int ret = 0;

    if (argc < 3)
    {
        printf("usage: ./a.out filename1 filename2\n"); 
        goto err0;
    }
    //以rb的方式打开文件
    fin = fopen(argv[1], "rb");
    if (NULL == fin)
    {
        printf("fopen file error..\n"); 
        goto err0;
    }
    //以wb的方式打开文件
    fout = fopen(argv[2], "wb");
    if (NULL == fout)
    {
        printf("fopen file error...\n"); 
        goto err0;
    }

    while(1)
    {
        //读二进制文件
        ret = fread(buf, sizeof(char), 32, fin);  
        printf("ret = %d\n", ret);
        if (0 == ret)
            break;
        //写二进制文件
        fwrite(buf, sizeof(char), ret, fout); 
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
