#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define SIZE 1000000

//全局变量
unsigned long val = 0;
//初始化mutex锁
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *fun1(void *args)
{
    unsigned long i = 0;
    printf("thread id: %lu  args: %s\n", pthread_self(), (char*)args);

    //加锁
    pthread_mutex_lock(&mutex);
    for (i = 0; i < SIZE; i++)
        val++;

    printf("thread 1 val = %lu\n", val);
    //解锁
    pthread_mutex_unlock(&mutex);

    pthread_exit((void*)0x1);
}

void *fun2(void *args)
{
    unsigned long i = 0;
    printf("thread id: %lu  args: %s\n", pthread_self(), (char*)args);
    for (i = 0; i < SIZE; i++)
    {
        //加锁
        pthread_mutex_lock(&mutex);
        val++;
        //解锁
        pthread_mutex_unlock(&mutex);
    }

    printf("thread 2 val = %lu\n", val);

    pthread_exit((void*)0x2);
}

//对全局变量修改 没有加锁的情况 会出现数据不一致的问题
int main(void)
{
    void *val = NULL;
    pthread_t tid[2];

    //创建线程
    pthread_create(&tid[0], NULL, fun1, "thread 1");
    pthread_create(&tid[1], NULL, fun2, "thread 2");

    //等待第一个线程
    if (pthread_join(tid[0], &val) != 0)
    {
        printf("join 线程1失败....\n"); 
    }
    printf("val = %#x\n", (unsigned long)val);

    //等待第二个线程
    if (pthread_join(tid[1], &val) != 0)
    {
        printf("join 线程2失败....\n"); 
    }
    printf("val = %#x\n", (unsigned long)val);

    if (pthread_mutex_destroy(&mutex) != 0)
    {
        printf("销毁信号量失败....\n"); 
    }

    return 0;
}

