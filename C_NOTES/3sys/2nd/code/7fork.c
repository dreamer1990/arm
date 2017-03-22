#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//pid_t ---> int 类型

//创建一个子进程
//pid_t fork(void);

int main(void)
{

    pid_t pid = 0;

    pid = fork();

    //子进程
    if (0 == pid)
    {
        printf("pid = %d\n", pid);
        printf("pid: %u  ppid: %u\n", getpid(), getppid());
        printf("I am child process...\n"); 
        //子进程退出
        exit(0);
    }
    
    //父进程所做的事情
    printf("pid = %d\n", pid);
    printf("I am prarent process....\n");
    printf("==>pid: %u  ppid: %u\n", getpid(), getppid());



    return 0;
}
