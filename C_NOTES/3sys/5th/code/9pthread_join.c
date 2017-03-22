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
 *int pthread_join(pthread_t thread, void **retval);
 *功能: 等待指定的线程结束
 *参数:
 *    thread 线程ID
 *    retval 接收指定线程退出时的状态
 *返回值:
 *    成功 0 
 *    失败 错误号
 *
 */


void *fun1(void *args)
{
    int i = 0;
    //输出线程相关信息
    printf("thread id: %lu  args: %s\n", pthread_self(), (char*)args);

    while(1)
    {
        printf("Thread 1 do work...\n");
        i++;
        sleep(1);
        if (10 == i)
            break;
    }
   
    //线程退出  返回状态为0x1
    pthread_exit((void*)0x1);
}

void *fun2(void *args)
{
    //输出线程相关信息
    printf("thread id: %lu  args: %s\n", pthread_self(), (char*)args);
   
    //线程退出  返回状态为0x2
    pthread_exit((void*)0x2);
}

int main(void)
{

    int  ret = -1;   
    void *val = NULL;
    pthread_t tid1 = -1;
    pthread_t tid2 = -1;

    //线程执行是随机 执行顺序与创建顺序无关
    //创建一个线程
    if (pthread_create(&tid1, NULL, fun1, "thread 1") != 0) 
    {
        printf("创建线程失败....\n"); 
    }
    //创建一个线程
    if (pthread_create(&tid2, NULL, fun2, "thread 2") != 0) 
    {
        printf("创建线程失败....\n"); 
    }

    //会阻塞 直到指定的线程退出
    //等待第一个线程结束
    if (pthread_join(tid1, (void **)&val) != 0)
    {
        printf("等待指定线程失败....\n"); 
    }
    printf("线程1退出状态 val = %#x\n", (unsigned long)val);

    //等待第二个线程结束
    if (pthread_join(tid2, (void **)&val) != 0)
    {
        printf("等待第二个线程退出失败...\n"); 
    }
    printf("线程2退出状态 val = %#x\n", (unsigned long)val);


    //等待所有的线程退出之后 才会执行以下
    printf("Main thread Id: %lu\n", pthread_self());


    return 0;
}
