#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void fun(int sig)
{
    printf("当前信号为: %d\n", sig);
}

int main(void)
{

    int i = 0;

    //信号SIGABRT不能被忽略
    //if (signal(SIGABRT, SIG_IGN) == SIG_ERR)
    //如果产生了该SIGABRT信号 还是异常终止程序
    if (signal(SIGABRT, fun) == SIG_ERR)
    {
        perror("signal"); 
        goto err0;
    }

    for (i = 0; i < 10; i++)
    {
        printf("do work %d\n", i); 
        sleep(1);

        if (8 == i)
        {
            //使进程异常终止
            abort();
        }
    }



    return 0;
err0:
    return -1;
}
