#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>

#define SIZE 1000000

/*
 *
 *int pthread_mutex_destroy(pthread_mutex_t *mutex);
 *功能:销毁一个互斥量
 *参数:
 *mutex 互斥量指针
 *返回值:
 *成功 0
 *失败 错误号
 *
 *int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
 *功能:初始化互斥量
 *参数:
 *mutex 互斥量指针
 *attr  互斥量属性
 *返回值:
 *成功 0
 *失败 错误号
 *
 *静态的以默认的属性初始化互斥量变量
 *pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
 *
 *
 *int pthread_mutex_lock(pthread_mutex_t *mutex);
 *功能: 加锁
 *参数:
 *    mutex 互斥量类型指针
 *返回值:
 *    成功: 0
 *    失败: 错误号
 *
 *int pthread_mutex_trylock(pthread_mutex_t *mutex);
 *功能: 尝试加锁
 *参数:
 *    mutex 互斥量类型指针
 *返回值:
 *    成功: 0
 *    失败: 错误号
 *int pthread_mutex_unlock(pthread_mutex_t *mutex);
 *功能: 解锁
 *参数:
 *    mutex 互斥量类型指针
 *返回值:
 *    成功: 0
 *    失败: 错误号
 *
 */


pthread_mutex_t mutex;

void fun(int signum)
{
    printf("解锁一次......\n");
    if (pthread_mutex_unlock(&mutex) != 0)
    {
        printf("解锁失败...\n"); 
    }
}

int main(void)
{
    //pthread_mutex_t是结构体类型
    int ret = -1;
    int i = 0;

    //Attempting to initialize an already initialized mutex results in undefined behavior.
    //企图初始化一个已经初始化好的互斥量变量导致未定义的行为

    //It  shall be safe to destroy an initialized mutex that is unlocked.  Attempting to destroy a locked mutex results in undefined behavior.
    //销毁一个没有加锁的已经初始化的互斥量是安全的，企图销毁一个已经加锁的互斥量导致未定义行为

    //初始化一个互斥量 
    //使用静态初始化的方法 必须是定义的时候进行初始化
    //pthread_mutex_t mutex1 =  PTHREAD_MUTEX_INITIALIZER;

    //以默认的属性初始化互斥量
    ret = pthread_mutex_init(&mutex, NULL);
    if (0 != ret)
    {
        printf("第一次初始化互斥量失败....\n"); 
    }

    //注册信号 
    signal(SIGINT, fun);



    for (i = 0; i < 5; i++)
    {
        if (pthread_mutex_lock(&mutex) != 0)
        {
            printf("第%d次加锁失败\n", i); 
        } 
        printf("第%d次加锁.....\n", i);

    }

    //处于锁定状态
    if (pthread_mutex_trylock(&mutex) != 0)
    {
        printf("尝试加锁失败...\n"); 
    }

    //解锁 不阻塞  如果加锁失败 就立即返回
    pthread_mutex_unlock(&mutex);

    //如果mutex处于锁住状态 则销毁失败
    if (0 != pthread_mutex_destroy(&mutex))
    {
        printf("第一次销毁互斥量失败...\n"); 
    }


    return 0;
}




