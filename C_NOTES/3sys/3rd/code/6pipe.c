#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


//父子进程间通信
//pipefd[0] 为读而打开  pipefd[1] 为写而打开
//int pipe(int pipefd[2])

int main(void)
{

    int ret = -1;
    int i = 0;
    int fd[2];
    char buf[32];
    pid_t pid = -1;

    //创建一个无名管道
    ret = pipe(fd);
    if (ret < 0)
    {
        perror("pipe"); 
        goto err0;
    }

    printf("fd[0] = %d fd[1] = %d\n", fd[0], fd[1]);

    pid = fork();
    //子进程 从管道读数据
    if (0 == pid)
    {
        //子进程关闭写端
        close(fd[1]);

        while(1)
        {
            //读写端已经关闭的管道  就会返回0
            //如果管道中没有数据 并且没有关闭写端 读管道的时候会阻塞
            ret = read(fd[0], buf, 32); 
            buf[ret] = '\0';
            printf("----> ret = %d buf: %s\n", ret, buf);

            if (0 == ret)
               break;
        }

        close(fd[0]);
        exit(0); 
    }

    //父进程
    //关闭读端
    close(fd[0]);
    while(1)
    {
        //从标准输入读取数据 然后写入管道
        fgets(buf, 32, stdin);
        ret = strlen(buf);
        buf[ret - 1] = '\0';

        if (strncmp(buf, "exit", 4) == 0)
            break;

        //向管道中写数据
        ret = write(fd[1], buf, ret);
        if (ret <= 0)
        {
            perror("write");
            break;
        }

        printf("parent ret = %d\n", ret);
    }

    close(fd[1]);
    return 0;
err0:
    return -1;
}






