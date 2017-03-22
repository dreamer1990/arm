#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


int main(void)
{
    int fd;
    int i = 0;
    int ret = 0;
    char buf[32];
    pid_t pid;

    //如果管道文件存在 就直接删除
    if (access("fifo", F_OK) == 0)
    {
        remove("fifo"); 
    }

    //新建一个管道文件
    ret = mkfifo("fifo", 0644);
    if (ret < 0)
    {
        perror("mkfifo"); 
        goto err0;
    }
    //读写方式打开文件
    fd = open("fifo", O_RDWR);
    if (fd < 0)
    {
        perror("open"); 
        goto err0;
    }

    pid = fork();

    //子进程
    if (0 == pid)
    {
        while(1)
        {
            ret = read(fd, buf, 32); 
            if (ret <= 0)
                break;
            buf[ret] = 0;
            printf("from fifo:  %s\n", buf);
        }

        close(fd);
        //子进程退出
        exit(0);
    }

    //父进程
    while(1)
    {
        ret = sprintf(buf, "hello world: %d", i++);        
        ret = write(fd, buf, ret);
        if (ret <= 0)
        {
            perror("write"); 
            break;
        }

        sleep(1);
    }


    close(fd);
    return 0;
err0:
    return -1;
}
