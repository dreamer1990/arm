#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/select.h>
#include <linux/input.h>
#include <string.h>
#include <poll.h>

#include "ioctl-dev.h"

int fd;
void func(int sig)
{
    char buf[100] = {};
    printf("sig: %d \n", sig);
    read(fd, buf, 100);
    printf("buf: %s\n", buf);
}

int main(int argc, char ** argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s dev_file(test)\n", argv[0]);
        return -1;
    }

    signal(SIGIO, func);

    int ret;
    fd = open(argv[1], O_RDWR); //--> test_open (test.ko)
    if(-1 == fd)
    {
        perror("open");
        return -1;
    }
    printf("fd : %d\n", fd);

    ret = fcntl(fd, F_SETOWN, getpid());  //把当前进程的pid告诉驱动;
    if(-1 == ret)
    {
        perror("fcntl");
        return -1;
    }
    ret = fcntl(fd, F_SETFL, fcntl(fd, F_GETFL) | O_NONBLOCK | O_ASYNC); //使用非阻塞的异步通知;
    if(-1 == ret)
    {
        perror("fcntl");
        return -1;
    }
    long i = 1000000000;
    while(1)
    {
        printf("main running \n");
        sleep(3);
    }

    close(fd);                  //--> test_close(test.ko)
    return 0;
}
