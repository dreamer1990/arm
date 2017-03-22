#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


typedef void (*sighandler_t)(int);

//信号处理函数
void fun(int signum)
{
    int ret = 0;
    printf("闹钟到点了...\n");
    //闹钟是一次性 到点之后必须重新设置
    ret = alarm(3);
    printf("ret = %d\n", ret);
}

int main(void)
{
    int ret = 0; 

    //注册闹钟信号处理方式
    if (signal(SIGALRM, fun) == SIG_ERR)
    {
        perror("signal"); 
        goto err0;
    }

    //设置闹钟时间 到点后自动产生SIGALRM信号
    ret = alarm(10);
    printf("ret = %d\n", ret);

    sleep(2);
    //如果上一次的闹钟没有 又重新设置 则原来的闹钟会被清除 
    ret = alarm(3);
    printf("====> ret = %d\n", ret);

    while(1)
        ;
    return 0;
err0:
    return -1;
}
