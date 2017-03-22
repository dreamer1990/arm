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

    //打开文件
    fd = open("txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("open"); 
        goto err0;
    }

    //赋值一个现存的文件描述符
    newfd = dup(fd);
    printf("fd:  %d  new_fd: %d\n", fd, newfd);

    //fd和newfd共用同一个文件表项
    write(fd, "AAAAA", 5);    
    write(newfd, "BBBBB", 5);

    //关闭文件的时候  两个文件描述符都要关闭
    close(newfd);
    close(fd);


    return 0;
err0:
    return -1;
}



