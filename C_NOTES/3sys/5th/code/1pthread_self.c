#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//线程是轻量级  大部分资源都是共用的
//进程是CPU分配资源的最小单位  
//线程是CPU调度的最小单位

/*
 *pthread_t ----> unsigned long
 *返回线程的ID  线程ID在同一个进程中 线程ID一定唯一
 *pthread_t pthread_self(void);
 *Compile and link with -pthread.
 *
 */

/*
 *编译要链接第三方库
 *[root@deng code]# gcc 1pthread_self.c -lpthread
 *[root@deng code]# ./a.out 
 *
 */

int main(void)
{

    //pthread_t是线程ID类型
    pthread_t tid;

    //返回主线程的ID
    tid = pthread_self();
    
    printf("tid = %p\n", tid);

    return 0;
}
