#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

//信号处理函数
void fun(int sig)
{
    printf("收到信号  信号为: %d\n", sig);
}

//显示当前信号集
void show_pending(sigset_t set)
{
    int i = 0;
    printf("当前处于未决状态的信号有:  ");
    for (i = 1; i < 32; i++)
    {
        if (sigismember(&set, i) == 1) 
        {
            printf("%2d  ", i); 
        }
    }
    //换行
    printf("\n");
}

int main(void)
{
    int ret = 0;
    int i = 0;

    sigset_t nset, oset;

    sigemptyset(&nset);
    sigaddset(&nset, SIGINT);
    sigaddset(&nset, SIGQUIT);
    
    //信号注册
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
    
    //阻塞当前SIGINT SIGQUIT两个信号
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
    //检查当前未决的信号 
    if (sigpending(&nset) == -1)
    {
        perror("sigpending"); 
        goto err0;
    }

    show_pending(nset); 
    printf("解除阻塞.....\n");
    //解除阻塞
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
