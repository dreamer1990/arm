#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//信号处理函数
void fun(int sig)
{
    printf("signum = %d\n", sig);
}


int main(void)
{
    //定义信号集变量
    sigset_t nset, oset;
    int ret = -1;
    int i = 0;

    //SIGINT SIGQUIT是不可靠信号 也不支持排队
    sigemptyset(&nset);
    sigaddset(&nset, SIGINT);
    sigaddset(&nset, SIGQUIT);

    if (signal(SIGINT, fun) == SIG_ERR)
    {
        perror("signal");
        goto err0;
    }
    if (signal(SIGQUIT, fun) == SIG_ERR)
    {
        perror("signal"); 
        goto err0;
    }

    //读取原来阻塞的信号集
    ret = sigprocmask(SIG_BLOCK, &nset, &oset);
    if (-1 == ret)
    {
        perror("sigprocmask"); 
        goto err0;
    }

    for(i = 0; i < 10; i++)
    {
        printf("do work %d\n", i); 
        sleep(1);
    }

    //如果之前产生多个SIGINT信号  那么最终解除信号之前  也只会接收到一个对应的信号
    printf("解除阻塞....\n");
    if (sigprocmask(SIG_SETMASK, &oset, NULL) == -1)
    {
        perror("sigprocmask"); 
        goto err0;
    }

    sleep(5);

    return 0;
err0:
    return -1;
}
