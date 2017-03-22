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
    int fd_r, fd_w;
    int ret;
    char buf[SIZE];


    //创建管道文件
    if (access("fifo_1", F_OK) != 0)
    {
        //创建管道文件
        if (mkfifo("fifo_1", 0644) < 0)
        {
            perror("mkfifo"); 
            goto err0;
        }
    }

    //创建管道文件
    if (access("fifo_2", F_OK) != 0)
    {
        //创建管道文件
        if (mkfifo("fifo_2", 0644) < 0)
        {
            perror("mkfifo"); 
            goto err0;
        }
    }

    
/*
 *    打一个FIFO时,没有设置O_NONBLOCK产生下列影响
 *     .读打开FIFO要阻塞到其他进程为写而打开,同样,写打开要阻塞到某个进程为读打开
 *     .如果指定了O_NONBLOCK,则只读open立即返回,那么只写open将出错返回-1,errno==ENXIO
 *
 */

    //打开顺序不能写反
    
    //以读写的方式打开管道文件
    fd_w = open("fifo_1", O_WRONLY);
    if (fd_w < 0)
    {
        perror("open"); 
        goto err0;
    }

    //以读写的方式打开管道文件
    fd_r = open("fifo_2", O_RDONLY);
    if (fd_r < 0)
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

        //写数据
        ret = write(fd_w, buf, strlen(buf));
        if (ret <= 0)
        {
            perror("write");  
            break;
        }
        printf("write %d bytes...\n", ret);

        
        //读数据
        ret = read(fd_r, buf, SIZE);    
        if (ret <= 0)
        {
            perror("read"); 
            break;
        }
        buf[ret] = 0;
        printf("---> ret = %d buf: %s\n", ret, buf);

    }

    printf("================write============\n");
    //关闭管道文件
    close(fd_r);
    close(fd_w);

    return 0;
err0:
    return -1;
}
