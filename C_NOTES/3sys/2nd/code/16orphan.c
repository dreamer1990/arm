#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//孤儿进程：父进程已经退出了 子进程还在运行
//孤儿进程最终会被1号init进程收养

//pstree -p | less

int main(void)
{
    pid_t pid = 0;


    pid = fork();

    //子进程
    if (0 == pid)
    {
        while(1)
        {
            printf("getppid: %d  hello world..\n", getppid()); 
            sleep(1);
        }
        exit(0);
    }
    
    printf("pid = %d\n", getpid()); 
    printf("The parent process if end of life...\n");

    return 0;
}
