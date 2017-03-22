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


    //创建管道文件
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
        //读数据
        ret = read(fd, buf, SIZE);    
        if (ret <= 0)
        {
            perror("read"); 
            break;
        }

        buf[ret] = 0;
        printf("ret = %d buf: %s\n", ret, buf);
    }

    //关闭管道文件
    close(fd);
    return 0;
err0:
    return -1;
}
