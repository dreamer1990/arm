#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;

    char ch;

    unsigned long i = 0;

    unsigned long sum = 0;

    pid = fork();

    //子进程先运行 还是父进程先运行 不确定
    //子进程
    if (0 == pid)
    {

        for (ch = 'A'; ch <= 'Z'; ch++)
            putchar(ch);
        putchar('\n');
    
        for (i = 1; i <= 10000000; i++)
            sum += i;
        printf("child process  sum = %lu\n", sum); 
            
        //进程退出
        exit(0);
    }

    //父进程
    for (ch = 'a'; ch <= 'z'; ch++)
        putchar(ch);
    putchar('\n');

    for (i = 2; i <= 10000000; i += 2)
        sum += i;
    printf("parent process sum = %lu\n", sum);

    return 0;
}


