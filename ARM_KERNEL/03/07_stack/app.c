#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#include "ioctl-dev.h"

int main(int argc, char ** argv)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s dev_file(test)\n", argv[0]);
        return -1;
    }

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
    ret = read(fd, buf, 100); 
    if(-1 == ret)
    {
        perror("read");
        return -1;
    }
    printf("buf: %s\n", buf);

    close(fd);                  //--> test_close(test.ko)
    return 0;
}
