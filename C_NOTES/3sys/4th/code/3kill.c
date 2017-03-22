#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int main(void)
{
    pid_t pid = -1;
    int i = 0;
    int ret = -1;
    
    //创建一个子进程
    pid = fork();
    if (pid < 0)
    {
        //创建进程失败
        perror("fork"); 
        goto err0;
    }
    else if (0 == pid)
    {
        //子进程 
        while(1)
        {
            printf("child do work %d\n", i); 
            i++; 
            sleep(1);
        } 

        //退出
        exit(0);
    }
    //父进程
    printf("parent do work...\n");
    sleep(5);
    printf("parent will kill child...\n");
    //向指定的进程 发送SIGINT信号
    ret = kill(pid, SIGINT);
    //自己给自己发送信号
    //ret = kill(getpid(), SIGINT);
    if (ret < 0)
    {
        perror("kill"); 
        goto err0;
    }


    return 0;
err0:
    return -1;
}
