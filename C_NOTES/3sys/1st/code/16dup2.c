
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


/*
 *
 *    int ret=dup2(old,new)
 *    如果new 打开的，则关闭new 返回新的文件描述符 失败返回－1. du2是一个原子操作。
 *    dup2可以用newfd参数指定新描述符的数值。如果newfd当前已经打开，则先将其关闭再做dup2操作，如果oldfd等于newfd，则dup2直接返回newfd而不用先关闭newfd再复制。
 *
 */


int main(void)
{
    int newfd = 3;
    int ret = 0;

    ret = dup2(STDOUT_FILENO, newfd);
    if (ret < 0)
    {
        perror("dup2"); 
        goto err0;
    }

    printf("newfd: %d\n", newfd);

    while(1)
    {
        write(newfd, "hello world\n", 12); 
        sleep(1);
    }


    close(newfd);
    return 0;
err0:
    return -1;
}






