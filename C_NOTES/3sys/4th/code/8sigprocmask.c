#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


int main(void)
{
    //定义信号集变量
    sigset_t oset;
    int ret = -1;
    int i = 0;

    //读取原来阻塞的信号集
    ret = sigprocmask(SIG_BLOCK, NULL, &oset);
    if (-1 == ret)
    {
        perror("sigprocmask"); 
        goto err0;
    }

    printf("阻塞的信号的编号为: ");
    for (i = 1; i < 65; i++)
    {
        if (sigismember(&oset, i) == 1) 
        {
            printf("%d  ", i); 
        }
    }
    //换行
    putchar('\n');


    return 0;
err0:
    return -1;
}
