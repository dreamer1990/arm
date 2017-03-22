#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


//全局变量  放在数据段
int n1 = 33;

//全局变量 放在为初始化的数据段中
int n2;

int main(void)
{
    //栈
    int n3 = 44;
    int *p = NULL;
    pid_t pid = 0;

    //分配一个字节
    p = malloc(sizeof(int));
    if (NULL == p)
    {
        perror("malloc"); 
        goto err0;
    }

    *p = 88;

    //创建一个子进程
    pid = fork();

    //子进程
    if (0 == pid)
    {
        printf("============child process=============\n");
        printf("---> n1 = %d n2 = %d\n", n1, n2); 
        printf("---> n3 = %d *p = %d\n", n3, *p);
        printf("===========child end==================\n");
        free(p);
        exit(0); 
    }

    //父进程
    printf("============parent process=============\n");
    printf("====> n1 = %d n2 = %d\n", n1, n2); 
    printf("====> n3 = %d *p = %d\n", n3, *p);
    free(p);
    printf("===========parent end==================\n");
 

    return 0;
err0:
    return -1;
}





