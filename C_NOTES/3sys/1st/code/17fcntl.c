#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


//int fcntl(int fd, int cmd, ... /* arg */ );

int main(void)
{
    int fd = 0;
    int newfd = 0;
    int ret = 0;


    fd = open("txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("open"); 
        goto err0;
    }

    //F_DUPFD 赋值一个现存的文件描述符
    newfd = fcntl(fd, F_DUPFD, 5);
    printf("fd = %d  newfd: %d\n", fd, newfd);

    write(fd, "AAAA\n", 5);
    write(newfd, "BBBB\n", 5);

    //F_GETFD    获取文件描述符的标志
    ret = fcntl(fd, F_GETFL, 0); 
    printf("ret = %#x\n", ret);
    switch(ret & O_ACCMODE)
    {
        case O_RDWR:
            printf("文件可以读写\n");
            break;
        case O_RDONLY: 
            printf("文件可以读\n");
            break;
        case O_WRONLY:
            printf("文件可以写\n");
            break;
    
        default:
            printf("other\n");
    }

    if (ret & O_NONBLOCK)
        printf("非阻塞的方式...\n");
    if (ret & O_APPEND)
        printf("以追加的方式...\n");

    //设置文件状态标志
    ret = ret | O_APPEND;
    fcntl(fd, F_SETFL, ret);
    sleep(1);

    printf("=====================\n");
    ret = fcntl(fd, F_GETFL, 0);
    if (ret & O_NONBLOCK)
        printf("非阻塞的方式...\n");
    if (ret & O_APPEND)
        printf("以追加的方式...\n");

    close(newfd);
    close(fd);

    return 0;
err0:
    return -1;
}

