#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
 *void pthread_exit(void *retval);
 *功能: 终止一个线程
 *参数:
 *    retval 返回状态
 *返回值:
 *    无
 *
 */

void *fun(void *args)
{
    //输出线程相关信息
    printf("thread id: %lu  args: %s\n", pthread_self(), (char*)args);
   
    //线程退出  返回状态为0x1
    pthread_exit((void*)0x1);
}

int main(void)
{

    pthread_t tid = -1;

    //创建一个线程
    if (pthread_create(&tid, NULL, fun, "thread 1") != 0) 
    {
        printf("创建线程失败....\n"); 
    }

    printf("Main thread Id: %lu\n", pthread_self());

    sleep(1); 

    return 0;
}
