#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int main(void)
{

    int var = 88;
    pid_t pid = 0;
    int *p = NULL;

    p = malloc(sizeof(int));
    if (NULL == p)
    {
        perror("malloc"); 
        goto err0;
    }

    //vfork的子进程是在父进程的空间中执行
    //vfork与fork功能类似 但是vfork保证子进程先执行
    //创建一个子进程
    pid = vfork();


    //子进程
    if (0 == pid)
    {
        printf("---> var = %d\n", var);
        var++;
        printf("---> var = %d\n", var);
        *p = 88;
        //在子进程中free
        free(p);
        exit(0); 
    }

    //父进程
    printf("var = %d\n", var);
    //printf("*p = %d\n", *p);
    //free(p);

    return 0;
    //exit(0);
err0:
    return -1;
}

