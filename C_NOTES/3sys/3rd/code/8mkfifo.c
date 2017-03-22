#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main(void)
{
    int fd = 0; 

    if (access("fifo", F_OK) == 0)
    {
        remove("fifo"); 
    }

    //创建一个有名管道
    fd = mkfifo("fifo", 0644);
    if (fd < 0)
    {
        perror("mkfifo"); 
        goto err0;
    }

    //管道文件不能lseek
    if (lseek(fd, 0, SEEK_END) < 0)    
    {
        perror("lseek"); 
    }

    printf("fd = %d\n", fd);

    return 0;
err0:
    return -1;
}


