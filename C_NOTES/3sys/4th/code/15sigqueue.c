#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(void)
{
    int i = 0;
    pid_t pid = -1;

    union sigval val;
    val.sival_ptr = NULL;


    //创建子进程
    pid = fork();
    if (0 == pid)
    {
        //子进程 
        while(1)
        {
            printf("do work %d\n", ++i); 
            sleep(1);
        }

        exit(0);
    }

    //父进程
    for (i = 0; i < 5; i++)
    {
        printf("parent do work %d\n", i); 
        sleep(1);
    }
    //向指定进程发送信号
    if (sigqueue(pid, SIGINT, val) == -1)
    {
        perror("sigqueue"); 
        goto err0;
    }

    wait(NULL);

    return 0;
err0:
    return -1;
}




