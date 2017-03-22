#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int main(void)
{

    char ch;
    pid_t pid = 0;

    //vfork与fork功能类似 但是vfork保证子进程先执行
    //创建一个子进程
    pid = vfork();

    //子进程
    if (0 == pid)
    {
        for (ch = 'A'; ch <= 'Z'; ch++)
            putchar(ch);
        putchar('\n'); 
        exit(0); 
    }

    //父进程
    for (ch = 'a'; ch <= 'z'; ch++)
        putchar(ch);
    putchar('\n'); 


    return 0;
    //exit(0);
}

