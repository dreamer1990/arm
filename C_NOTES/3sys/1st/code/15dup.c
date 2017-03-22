#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>



int main(void)
{
    int fd = 0;
    int newfd = 0;
    int ret = 0;


    fd = open("txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0)
    {
        perror("open"); 
        goto err0;
    }

    //关闭标准输入
    close(STDIN_FILENO);

    //返回当前进程最小的没有使用的文件描述符
    newfd = dup(fd);
    printf("fd = %d  newfd = %d\n", fd, newfd);

    write(newfd, "AAAAA", 5);
    

    //关闭文件
    close(fd);
    close(newfd);

    return 0;
err0:
    return -1;
}
