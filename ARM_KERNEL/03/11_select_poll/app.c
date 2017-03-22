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

void func(int sig)
{
    printf("sig: %d \n", sig);
}

int main(int argc, char ** argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s dev_file(test)\n", argv[0]);
        return -1;
    }

    signal(SIGINT, func);

    int fd;
    int ret;
    fd = open(argv[1], O_RDWR); //--> test_open (test.ko)
    if(-1 == fd)
    {
        perror("open");
        return -1;
    }
    printf("fd : %d\n", fd);

    char buf[100];
    struct input_event event;

    struct pollfd fds[2] = {};      //同时监听多个文件描述符号;
    fds[0].fd = fd;                 //设备fd
    fds[0].events = POLLIN;         //有数据可读;
    fds[1].fd = 0;                  //标准输入fd;
    fds[1].events = POLLIN;

    while(1)
    {
        ret = poll(fds, 2, -1);     //统一阻塞等待两个; 
        if(-1 == ret)
        {
            perror("select");
            return -1;
        }
        else if(0 == ret)
        {
            printf("time out\n");
            continue;
        }
        else                        //ret>0 表示至少有一个醒来了;
        {
            if(fds[0].revents == fds[0].events)
            {
                //ret = read(fd, &event, sizeof(event)); 
                //printf("ret : %d type: %d code:%d value:%d\n", ret, 
                //        event.type, event.code, event.value);
                ret = read(fd, buf, 10); 
                printf("ret: %d buf: %s\n", ret, buf);
            }
            if(fds[1].revents == fds[1].events)
            {
                ret = read(0, buf, 10); 
                printf("ret: %d buf: %s\n", ret, buf);
            }
        }
    }
    close(fd);                  //--> test_close(test.ko)
    return 0;
}
