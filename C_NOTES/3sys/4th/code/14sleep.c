#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void fun(int sig)
{

}

int my_sleep(int n)
{
    //闹钟
    alarm(n);
    //等待闹钟信号
    pause();
}

int main(void)
{
    int i = 0;

    //信号注册
    //此处信号不能被忽略 如果被忽略了信号就会丢失
    //if (signal(SIGALRM, SIG_IGN) == SIG_ERR)
    if (signal(SIGALRM, fun) == SIG_ERR)
    {
        perror("signal"); 
        goto err0;
    }

    for (i = 0; i < 10; i++)
    {
        printf("do work  %d\n", i); 
        my_sleep(1);
    }


    return 0;
err0:
    return -1;
}
