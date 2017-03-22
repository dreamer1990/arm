#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


//1 是命令  2 系统调用  3库函数  
//man 3 exit
//exit 是库函数 不是系统调用

int main(void)
{


    printf("hello uplooking..\n");


    //查看返回的状态 在父进程中echo $?
    //返回的状态值就是  status & 0xff的结果
    //exit 与return语句等价
    //exit(-1);
    //立即返回  
    //_exit(1);
    _Exit(2);
}


