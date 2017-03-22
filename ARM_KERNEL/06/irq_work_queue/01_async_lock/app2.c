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

    fd_set readfds;
    while(1)
    {
        FD_ZERO(&readfds);
        FD_SET(fd, &readfds);
        FD_SET(0, &readfds);

        ret = select(fd + 1, &readfds, NULL, NULL, NULL);
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
        else
        {
            if(FD_ISSET(fd, &readfds))
            {
                //ret = read(fd, &event, sizeof(event)); 
                //printf("ret : %d type: %d code:%d value:%d\n", ret, 
                //        event.type, event.code, event.value);
                ret = read(fd, buf, 10); 
                printf("ret: %d buf: %s\n", ret, buf);
                memset(buf, 0, 100);
            }
            if(FD_ISSET(0, &readfds))
            {
                ret = read(0, buf, 10); 
                printf("ret: %d buf: %s\n", ret, buf);
                memset(buf, 0, 100);
            }
        }
    }
    close(fd);                  //--> test_close(test.ko)
    return 0;
}
