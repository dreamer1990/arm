#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/*
 * 操作方法
 *[root@deng /]# kill -SIGUSR2 4175
 *[root@deng /]# kill -SIGUSR1 4175
 *[root@deng /]# kill -USR1 4175
 *[root@deng /]# kill -USR2 4175
 *[root@deng /]# 
 *
 */

typedef void (*sighandler_t)(int);

//信号处理函数
void fun(int signum)
{
    if (signum == SIGUSR1)
        printf("user signal1 num: %d\n", signum);
    else if (signum == SIGUSR2)
        printf("user signal2 num: %d\n", signum);
    else
        printf("signal num: %d\n", signum);
}

int main(void)
{
    //定义函数指针变量
    sighandler_t pret = NULL; 

    //注册信号处理方式
    pret = signal(SIGUSR1, fun);
    if (SIG_ERR == pret)
    {
        perror("signal"); 
    }

    pret = signal(SIGUSR2, fun);
    if (SIG_ERR == pret)
    {
        perror("signal"); 
    }

    //等待信号产生
    while(1)
        ;
    return 0;
}




