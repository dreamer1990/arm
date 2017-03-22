#include <stdio.h>
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
    int buf[32];

    //创建无名管道
    ret = pipe(fd);
    if (ret < 0)
    {
        perror("pipe");
        goto err0;
    }

    write(fd[1], "hello world", 11);
    memset(buf, 0, 32);
    read(fd[0], buf, 32);
    printf("buf:  %s\n", buf);


    return 0;
err0:
    return -1;
}
