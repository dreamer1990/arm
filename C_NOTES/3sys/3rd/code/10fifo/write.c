#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 32

int main(void)
{
    int fd;
    int ret;
    char buf[SIZE];

    if (access("fifo", F_OK) != 0)
    {
        //创建管道文件
        if (mkfifo("fifo", 0644) < 0)
        {
            perror("mkfifo"); 
            goto err0;
        }
    }

    //以读写的方式打开管道文件
    fd = open("fifo", O_RDWR);
    if (fd < 0)
    {
        perror("open"); 
        goto err0;
    }

    while(1)
    {
        fgets(buf, SIZE, stdin);

        if (strncmp(buf, "exit", 4) == 0)
            break;

        buf[strlen(buf) - 1] = 0;

        //写书据
        ret = write(fd, buf, strlen(buf));
        if (ret <= 0)
        {
            perror("write");  
            break;
        }

        printf("write %d bytes...\n", ret);
    }

    //关闭管道文件
    close(fd);
    return 0;
err0:
    return -1;
}
