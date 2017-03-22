#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void fun(int sig)
{
    printf("收到信号为%d\n", sig);
}



int main(void)
{

    //等价于signal
    //结构体变量
    struct sigaction act, oact;

    //信号操作函数
    act.sa_handler = fun;
    //清空阻塞集
    sigemptyset(&act.sa_mask);

    if (sigaction(SIGINT, &act, &oact) == -1)
    {
        perror("sigaction"); 
        goto err0;
    }

    if (sigaction(SIGQUIT, &act, &oact) == -1)
    {
        perror("sigaction"); 
        goto err0;
    }
    
    pause();
    pause();

    return 0;
err0:
    return -1;
}



