#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>

#include <linux/types.h>
#include <linux/input.h>



struct js_event {
    __u32 time;     /* event timestamp in milliseconds */
    __s16 value;    /* value */
    __u8 type;      /* event type */
    __u8 number;    /* axis/button number */
};

int main(void)
{
    int fd = 0;
    int ret = 0;

    fd_set fset;

    struct timeval tmo = {
        .tv_sec = 3,
        .tv_usec = 0,
    };
    
    //定义事件结构体变量
    struct js_event e;

    //打开设备 只读和非阻塞的方式打开
    fd = open("/dev/input/event11", O_RDONLY);
    if (fd < 0)
    {
        perror("open"); 
        goto err0;
    }

    printf("fd = %d\n", fd);

    FD_ZERO(&fset);
    FD_SET(fd, &fset);

    while(1)
    {
        tmo.tv_sec = 3;
        tmo.tv_usec = 0;

        FD_ZERO(&fset);
        FD_SET(fd, &fset);

        ret = select(fd + 1, &fset, NULL, NULL, &tmo);
        if (ret < 0)
        {
            perror("select");      
            continue;
        }
        else if (0 == ret)
        {
            printf("3s time out....\n"); 
            continue;
        }
        else
        {
            if (FD_ISSET(fd, &fset))  
            {
                ret = read(fd, &e, sizeof(e)); 
                printf("time: %u value: %d type: %u  number: %u\n", e.time, e.value, e.type, e.number);
            }
        }
    }

    
    close(fd);

    return 0;
err0:
    return -1;
}


