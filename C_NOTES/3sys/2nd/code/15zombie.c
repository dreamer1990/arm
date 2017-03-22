#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/*
 *
 *14.僵尸进程： 子进程运行结束， 父进程还在运行中，
 *   而且父进程没收回收子进程的资源. 子进程就变为僵尸进程
 *
 */

int main(void)
{
    pid_t pid = 0;

    pid = fork();

    //产生子进程
    if (0 == pid)
    {
        printf("child pid: %d\n", getpid()); 
        exit(0);
    }

    //子进程退出 父进程还在睡觉 子进程变为僵尸进程
    sleep(10);

    return 0;
}
