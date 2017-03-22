#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *fun1(void *args)
{
    printf("thread id: %lu  args: %s\n", pthread_self(), (char*)args);
    while(1)
    {
        printf("do work.....\n"); 
        sleep(1);
    }

    pthread_exit((void*)0x1);
}

void *fun2(void *args)
{
    printf("thread id: %lu args: %lu\n", pthread_self(), *(unsigned long *)args);
    sleep(5);
    //取消另外一个线程
    pthread_cancel(*(unsigned long *)args);
    printf("取消第一个线程....\n");
    pthread_exit((void*)0x2);
}

int main(void)
{
    void *val = NULL;
    pthread_t tid[2];
    
    //创建线程
    pthread_create(&tid[0], NULL, fun1, "thread 1");
    pthread_create(&tid[1], NULL, fun2, &tid[0]);

    //等待第一个线程
    if (pthread_join(tid[0], &val) != 0)
    {
        printf("join 线程1失败....\n"); 
    }
    if (val == PTHREAD_CANCELED)
    {
        printf("线程1返回的状态为PTHREAD_CANCELED\n");
    }


    //等待第二个线程
    if (pthread_join(tid[1], &val) != 0)
    {
        printf("join 线程2失败....\n"); 
    }
    printf("val = %#x\n", (unsigned long)val);


    return 0;
}

