#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>



//检测进程退出的状态
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
    int status;
    int i;
    int ret;
    pid_t pid;

    //由一个父进程派生4个子进程
    for (i = 0; i < 10; i++)
    {
        pid = fork();
        if (0 == pid)
        {
            for (i = 0; i < 5; i++) 
            {
                printf("pid: %d hello uplooking....\n", getpid()); 
                sleep(1);
            }

            exit(0);
        }
    }


    //与wait(&status);等价
    //waitpid(-1, &status, 0);
    //等待所有的子进程退出
    while(1)
    {
        //非阻塞的方式等待所有的子进程退出
        ret = waitpid(-1, &status, WNOHANG); 
        if (ret < 0)
        {
            printf("没有子进程\n"); 
            break;
        }
        //如果没有出错 并且没有子进程退出  则返回0
        if (0 == ret)
            continue;
        printf("ret = %d\n", ret);

    }

    check_status(status);


    return 0;
}





















