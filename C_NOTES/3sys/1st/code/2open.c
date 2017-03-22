#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//int open(const char *pathname, int flags, mode_t mode);
/*
 *
 *    可选项：
 *    O_APPEND   每次写操写都将文件指针定位文件尾处
 *    O_CREAT    如果文件不存在创建新文件
 *    O_EXCL     如指定O_CREAT时文件存在 出错返回
 *    O_TRUNC    必须以O_WRONL或O_RDWR进行操作,把文件清空
 *
 */

int main(void)
{

    int fd = 0;

    //以只读的方式打开文件  如果文件不存在则创建文件
    //0644 前面的0是特权位 一般默认为0
    //fd = open("txt", O_RDONLY | O_CREAT, 0644);
    //如果文件已经存在则出错返回
    //fd = open("txt", O_RDONLY | O_CREAT | O_EXCL, 0644);
    //O_TRUNC必须是以写的方式  将文件内容清空
    fd = open("txt", O_RDWR | O_TRUNC);
    if (fd < 0)
    {
        perror("open"); 
        goto err0;
    }

    printf("fd = %d\n", fd);

    return 0;
err0:
    return -1;
}

