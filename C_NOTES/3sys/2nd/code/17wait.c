#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int check_status(int status)
{
    //正常退出
    if (WIFEXITED(status))
    {
        printf("子进程是正常退出的...\n");
    
        printf("退出状态为:  %d\n", WEXITSTATUS(status));
    }

    if (WIFSIGNALED(status))
    {
        printf("子进程被信号杀死....\n"); 
        printf("Signal: %d\n", WTERMSIG(status));
    }

    if (WCOREDUMP(status))
    {
        printf("子进程引起内核崩溃...\n"); 
    }

    if (WIFSTOPPED(status))
    {
        printf("子进程被传递的信号杀死...\n"); 
        printf("Signal: %d\n", WSTOPSIG(status));
    }

    if (WIFCONTINUED(status))
    {
        printf("子进程被信号唤醒...\n"); 
    }

    return 0;
}

int main(void)
{
    int i = 0;
    int status;
    pid_t pid = 0;

    pid = fork();

    //子进程
    if (0 == pid)
    {
        for (i = 0; i < 10; i++)   
        {
            printf("pid: %d  hello world\n", getpid());
            sleep(1);
        }
    
        exit(10);
    }

    //父进程
    //阻塞父进程  直到有一个子进程退出
    //返回值是子进程ID号
     pid = wait(&status);
    printf("pid = %d status: %d\n", pid, status);
    //检查子进程退出的状态
    check_status(status);


    return 0;
}
