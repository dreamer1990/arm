#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/*
 *清空信号集
 *int sigemptyset(sigset_t *set);
 *将所有的信号包含到信号集set中
 *int sigfillset(sigset_t *set);
 *添加信号到信号集set中
 *int sigaddset(sigset_t *set, int signum);
 *从信号集set中删除指定的信号
 *int sigdelset(sigset_t *set, int signum);
 *测试指定的信号是否为信号集中的一个成员
 *int sigismember(const sigset_t *set, int signum);
 *
 */

int main(void)
{
    int ret = -1;
    //定义一个信号集类型的变量
    sigset_t set;

    //清空信号
    ret = sigemptyset(&set);
    if (ret == -1)
    {
        perror("sigemptyset"); 
        goto err0;
    }
    //添加指定的信号到信号集中
    ret = sigaddset(&set, SIGINT);
    if (ret == -1)
    {
       perror("sigaddset");  
       goto err0;
    }
    //测试一个信号是否在信号集中
    if (sigismember(&set, SIGINT) == 1)
    {
        printf("The SIGINT is in set..\n"); 
    }

    if (sigismember(&set, SIGQUIT) == 0)
    {
        printf("The SIGQUIT is not in set..\n"); 
    }
    printf("set: %p\n", set);

    printf("sizeof(unsiged long): %d\n", sizeof(unsigned long));

    //从信号集中删除一个指定的信号
    if (sigdelset(&set, SIGINT) < 0)
    {
        perror("sigdelset"); 
        goto err0;
    }
    //测试一个信号是否在信号集中
    if (sigismember(&set, SIGINT) == 0)
    {
        printf("The SIGINT is not in set..\n"); 
    }

    //添加所有的信号到信号集中
    if (sigfillset(&set) < 0)
    {
        perror("sigfillset"); 
        goto err0;
    }

    //测试信号是否在信号集中
    if (sigismember(&set, SIGKILL) == 1)
    {
        printf("The SIGKILL is in set....\n"); 
    }


    return 0;
err0:
    return -1;
}


