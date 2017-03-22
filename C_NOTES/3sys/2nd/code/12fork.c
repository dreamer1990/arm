
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>



int main(void)
{
    int n1 = 33;
    pid_t pid = 0;

    pid = fork();

    //子进程
    if (0 == pid)
    {
        printf("---> n1 = %d\n", n1);    
        printf("&n1 = %p\n", &n1);
        n1++;
        printf("---> n1 = %d\n", n1);
        exit(0); 
    }

    //子进程拷贝父进程的数据段 栈 堆之后  他们互不影响
    //父进程
    sleep(1);
    printf("&n1 = %p\n", &n1);
    printf("===> n1 = %d\n", n1);


    return 0;
}
