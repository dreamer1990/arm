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
    
    /*
    ret = ioctl(fd, 0);
    if(-1 == ret)
    {
        perror("ioctl");
        return -1;
    }
    */
    
    struct led_set lset;
    lset.led_num = 0;
    while(1)
    {
        ioctl(fd, LED_ON);
        //ioctl(fd, LED_SET, 0);
        //lset.led_flag = 0;
        //ioctl(fd, LED_SETON, &lset);
        sleep(1);
        ioctl(fd, LED_OFF);
        //ioctl(fd, LED_SET, 1);
        //lset.led_flag = 1;
        //ioctl(fd, LED_SETON, &lset);
        sleep(1);
    }
    
    close(fd);                  //--> test_close(test.ko)
    return 0;
}
