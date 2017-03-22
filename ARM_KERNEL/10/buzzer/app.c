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
    
    ioctl(fd, PWM_IOCTL_SET_FREQ, 10);
    sleep(5);
    ioctl(fd, PWM_IOCTL_STOP);

    close(fd);
    return 0;
}
