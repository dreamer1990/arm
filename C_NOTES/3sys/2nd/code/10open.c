#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


int main(void)
{
    pid_t pid = 0;
    int fd = 0;
    char ch;

    //以读写的方式打开一个文件
    fd = open("txt", O_RDWR | O_CREAT , 0644);
    if (fd < 0)
    {
        perror("open");   
        goto err0;
    }

    //创建一个子进程
    pid = fork();


    //子进程
    if (0 == pid)
    {
        printf("child---->  fd = %d\n", fd);
        for (ch = 'A'; ch <= 'Z'; ch++) 
        {
            printf("child seek: %d\n", lseek(fd, 0, SEEK_CUR));
            write(fd, &ch, sizeof(char));
        }
        fflush(NULL); 
    }
    else
    {
        sleep(1);
        //父进程 
        printf("parent----> fd = %d\n", fd); 
        for (ch = 'a'; ch <= 'z'; ch++)
        {
            printf("parent seek: %d\n", lseek(fd, 0, SEEK_CUR));
            write(fd, &ch, sizeof(char));
        }
        fflush(NULL);
    }

    
    if (close(fd) < 0)
        perror("close");
    return 0;
err0:
    return -1;
}

