#include <stdio.h>

#define SIZE 32

//向文件中读写字符串
/*
 *    char *fgets(char *s, int size, FILE *stream);
 *    功能:从文件流中读取一个字符串,然后保存到s所指向的buf中
 *    参数:
 *        s: 指向保存字符串的buf
 *        size: 读取字符串的个数
 *        stream: 文件指针
 *    返回值:
 *        成功: 返回s
 *        失败: 返回NULL
 */

/*
 *    说明：
 *    fgets(str,n,fp);中n是要求得到的字符个数，但实际上只读n-1个字符，然后在最后加一个’\0’字符，这样得到的字符串共有n个字符，把它们放到字符数组str中
 *    如果在读完n-1个字符之前遇到换行符“\n”或文件结束符EOF，读入即结束，但将所遇到的换行符“\n”也作为一个字符读入
 *
 */

int main(void)
{
    char buf[32];
    FILE *fp = NULL;
    char *p = NULL;
    
    //打开文件
    fp = fopen("txt", "r");
    if (NULL == fp)
    {
        printf("fopen file failed...\n"); 
        goto err0;
    }

    //读取文件的内容
    while(!feof(fp))
    {
        p = fgets(buf, SIZE, fp); 
        //读取失败
        if (NULL == p)
            break;
        printf("%s", buf); 
    }

    //关闭文件
    fclose(fp);
    return 0;
err0:
    return -1;
}
