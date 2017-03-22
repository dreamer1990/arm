#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <linux/watchdog.h>

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
    
    struct watchdog_info info;
    ioctl(fd, WDIOC_GETSUPPORT, &info);
    printf("identity: %s\n", info.identity);

/*
    int stat;
    ioctl(fd, WDIOC_GETBOOTSTATUS, &stat);
    printf("stat: %d\n", stat);
*/
//    int val = WDIOS_DISABLECARD;
    //ioctl(fd, WDIOC_SETOPTIONS, &val);
    //sleep(10);

    int val;
    val = WDIOS_ENABLECARD;
    ioctl(fd, WDIOC_SETOPTIONS, &val);
    
    val = 2;
    ioctl(fd, WDIOC_SETTIMEOUT, &val);

    while(1)
    {
        printf("running ...\n");
        sleep(1);
        ioctl(fd, WDIOC_KEEPALIVE);
    }

    close(fd);
    return 0;
}
