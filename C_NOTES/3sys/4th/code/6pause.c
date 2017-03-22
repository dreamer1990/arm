#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//信号处理函数
void fun(int signum)
{
    printf("signum: %d\n", signum);

//    while(1)
    {
        printf("do work...\n"); 
 //       sleep(1);
    }

}

int main(void)
{
    //信号注册
    if (signal(SIGINT, fun) == SIG_ERR) 
    {
        perror("signal"); 
        goto err0;
    }

    //等待一个信号产生 然后返回 阻塞
    pause();

    return 0;
err0:
    return -1;
}

