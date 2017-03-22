#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//信号处理函数
void fun(int sig)
{
    printf("signum = %d\n", sig);
}

void show_mask(sigset_t set)
{
    int i = 0;
    printf("当前阻塞的信号有:   ");
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
    //查看原来阻塞的信号
    show_mask(oset);
    //查看当前阻塞的信号
    show_mask(nset);

    //临界区的代码
    for (i = 0; i < 5; i++)
    {
        printf("do work %d\n", i); 
        sleep(1);
    }

    printf("信号集中的信号解除...\n");
    //从阻塞的信号集中删除指定的信号 
    ret = sigprocmask(SIG_UNBLOCK, &nset, &oset);
    if (-1 == ret)
    {
        perror("sigprocmask"); 
        goto err0;
    }

    show_mask(oset);

    sleep(5);

    return 0;
err0:
    return -1;
}
