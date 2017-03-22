#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 128


/*
 *[root@deng 2.6.32-431.el6.x86_64]# pwd
 * /usr/src/kernels/2.6.32-431.el6.x86_64
 *[root@deng 2.6.32-431.el6.x86_64]# ctags  -Rn .  
 *ctrl + ] 跳过去
 *ctrl + t 跳回来
 *ctrl + o 跳回来
 *
 */


//typedef unsigned int size_t;
//typedef int ssize_t;

//ssize_t read(int fd, void *buf, size_t count);

int main(void)
{

    char buf[SIZE];
    int fd = -1;
    int ret = 0;

    //只读方式打开文件
    fd = open("txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");         
        goto err0;
    }

    //输出文件描述符
    printf("fd = %d\n", fd);

    //最多读SIZE个字节
    ret = read(fd, buf, SIZE - 1);
    buf[ret] = '\0';
    printf("ret = %d  buf: %s\n", ret, buf);
    



    //关闭文件
    close(fd);
    return 0;
err0:
    return -1;
}







