#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


//int open(const char *pathname, int flags);
//	flags 必须指其中O_RDONLY  O_WRONLY  O_RDWR唯一项
//	可选项：
//	O_APPEND   每次写操写都将文件指针定位文件尾处
//	O_CREAT    如果文件不存在创建新文件
//	O_EXCL     如指定O_CREAT时文件存在 出错返回
//	O_TRUNC    必须以O_WRONL或O_RDWR进行操作,把文件清空


int main(void)
{
    //文件描述符类型
    int fd = 0;

    //如果文件不存在 则出错返回
    // O_RDONLY    只读的方式打开
    // O_WRONLY    只写的方式打开
    // O_RDWR      读写的方式打开

    //只读的方式打开当前工作目录中的txt文件
    //fd = open("txt", O_RDONLY);
    //fd = open("txt", O_WRONLY);
    fd = open("txt", O_RDWR);
    if (fd < 0)
    {
        //perror是输出错误相关的信息
        perror("open"); 
        goto err0;
    }

    printf("open file successfully... fd: %d\n", fd);


    return 0;
err0:
    return -1;
}


