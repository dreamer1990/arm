#include <stdio.h>

/*
 *    int fseek(FILE *stream, long offset, int whence);
 *    功能： 重新定位文件指针
 *          stream: 文件指针
 *          offset: 偏移量
 *          whence: 从哪里开始
 *              SEEK_SET    文件开始的地方
 *              SEEK_CUR    文件当前位置
 *              SEEK_END    文件结束的地方
 *    返回值:
 *        成功: 0
 *        失败: -1
 *
 */


int main(void)
{
    int ret = 0;
    FILE *fp = NULL;

    //打开文件,建立fp与指定的文件关联
    fp = fopen("txt", "r+");
    if (NULL == fp)
    {
        printf("fopen file error...\n"); 
        goto err0;
    }

    ret = fseek(fp, 0L, SEEK_END);
    printf("current position: %d\n", ftell(fp));

    ret = fseek(fp, -40, SEEK_CUR);
    printf("current position: %d\n", ftell(fp));
    
    //rewind(fp);
    fseek(fp, 0L, SEEK_SET);
    printf("current position: %d\n", ftell(fp));


    //关闭文件,释放资源
    fclose(fp);

    return 0;
err0:
    return -1;
}



