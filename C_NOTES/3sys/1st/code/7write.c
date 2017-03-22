#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int ret = 0;
    int fd = 0;

    //打开文件
    fd = open("txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("open"); 
        goto err0;
    }
    printf("fd = %d\n", fd);

    //向指定的文件描述符写数据
    ret = write(fd, "hello uplooking", strlen("hello uplooking"));
    printf("ret = %d\n", ret);

    //关闭文件
    close(fd);

    return 0;
err0:
    return -1;
}
