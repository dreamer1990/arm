#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void fun(int sig)
{
    printf("接收到信号: %d\n", sig);
}

int main(void)
{
    int i = 0;
    int ret = -1;
    sigset_t nset, oset;

    //清空信号集
    sigemptyset(&nset);
    //将信号添加到信号集中
    sigaddset(&nset, SIGINT);

    //注册信号
    if (signal(SIGINT, fun) == SIG_ERR) 
    {
        perror("signal"); 
        goto err0;
    }
     //注册信号
    if (signal(SIGQUIT, fun) == SIG_ERR) 
    {
        perror("signal"); 
        goto err0;
    }
    
    //设置阻塞的信号 
    if (sigprocmask(SIG_BLOCK, &nset, &oset) == -1)
    {
        perror("sigprocmask"); 
        goto err0;
    }

    //临界区代码
    for (i = 0; i < 10; i++)
    {
        printf("do work %d\n", i); 
        sleep(1);
    }
    //该函数也是阻塞型 原子操作
    //sigemptyset(&nset);
    //解除所有的阻塞 并且等待一个信号产生 返回之后 会还原原来的信号屏蔽集
    sigsuspend(&nset);
    
    //阻塞信号集回复到最初
    if (sigprocmask(SIG_SETMASK, &oset, NULL) == -1)
    {
        perror("sigprocmask"); 
        goto err0;
    }

    sleep(3);

    return 0;
err0:
    return -1;
}
