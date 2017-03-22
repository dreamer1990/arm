#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


//pipefd[0] 为读而打开  pipefd[1] 为写而打开
//int pipe(int pipefd[2])


int main(void)
{
    int fd[2];
    int ret = -1;
    char buf[32];
    pid_t pid = -1;

    //创建无名管道
    ret = pipe(fd);
    if (ret < 0)
    {
        perror("pipe");
        goto err0;
    }

    //派生一个子进程
    pid = fork();
    //子进程
    if (0 == pid)
    {
        //先关闭写端
        close(fd[1]);
        memset(buf, 0, 32);
        read(fd[0], buf, 32);
    
        printf("read from parent: %s\n", buf);
        printf("child exit....\n");
        close(fd[0]);
        exit(0); 
    }

    //父进程
    //关闭读端
    close(fd[0]);
    write(fd[1], "hello world", 11);
    close(fd[1]);

    wait(NULL);
    printf("parent exit...\n");
    return 0;
err0:
    return -1;
}






