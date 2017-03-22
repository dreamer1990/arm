#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "ioctl-dev.h"

int main(int argc, char ** argv, char **env)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s dev_file\n", argv[0]);
        return -1;
    }
    
    int fd;
    fd = open(argv[1], O_RDWR);
    if(-1 == fd)
    {
        perror("open");
        return -1;
    }


    ioctl(fd, WDT_SETTIMEOUT, 2);
    ioctl(fd, WDT_START);
    //ioctl(fd, WDT_SETIRQ);

    while(1)
    {
        printf("running ......\n");
        sleep(1);
        ioctl(fd, WDT_KEEPALIVE);
    }

    close(fd);
    return 0;
}
