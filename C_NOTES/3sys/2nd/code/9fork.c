#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{

    //2 ^ 3 = 8;
    //fork();
    //fork();
    //子进程会继承父进程大部分数据
    //子进程是父进程的一份拷贝
    fork();

    //pc也被继承
    printf("hello world\n");


    return 0;
}


