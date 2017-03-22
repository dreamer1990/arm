#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define PWM_IOCTL_SET_FREQ      1
#define PWM_IOCTL_STOP          0


int main(int argc, char ** argv, char **env)
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s dev_file.\n", argv[0]);
        return -1;
    }

    int fd;
    fd = open(argv[1], O_RDWR);
    if(-1 == fd)
    {
        perror("open");
        return -1;
    }
    
    char buf[20] = {};
    while(1)
    {
        read(fd, buf, 20);
        printf("adc AIN0: %s\n", buf);
        usleep(100000);
    }


    close(fd);
    return 0;
}
