#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

/*
 *
 *int pthread_attr_init(pthread_attr_t *attr);
 *功能: 初始化线程属性变量
 *int pthread_attr_destroy(pthread_attr_t *attr);
 *功能: 销毁线程属性变量
 *参数:
 *    attr  属性变量指针
 *返回值:
 *    成功: 0
 *    失败: 错误号
 *
 *int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate);
 *功能: 设置线程的分离状态
 *参数:
 *    attr 属性
 *    detachstate 分离的状态 PTHREAD_CREATE_DETACHED  PTHREAD_CREATE_JOINABLE
 *返回值:
 *    成功 0
 *    失败 错误号
 *
 *int pthread_attr_getdetachstate(pthread_attr_t *attr, int *detachstate);
 *功能: 获取线程的分离状态属性
 *参数:
 *    attr 属性
 *    detachstate 分离的状态 PTHREAD_CREATE_DETACHED  PTHREAD_CREATE_JOINABLE
 *返回值:
 *    成功 0
 *    失败 错误号
 *
 */

void *fun(void *args)
{
    printf("Thread ID: %lu  args: %s\n", pthread_self(), (char*)args);

    pthread_exit((void *)0x1);
}

int main(void)
{
    //线程属性变量
    pthread_attr_t attr; 
    pthread_t tid;
    int detachstate = -1;

    //初始化线程属性变量
    if (pthread_attr_init(&attr) != 0)
    {
        printf("pthread attr init failed...\n"); 
        goto err0;
    }

    //设置线程分离属性 默认是不分离
    if (pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED) != 0)
    {
        printf("attr setdetachstate failed...\n");  
        goto err0;
    }
    //创建线程  以指定的属性创建
    if (pthread_create(&tid, &attr, fun, "hello uplooking") != 0)
    {
        printf("pthread create failed...\n"); 
        goto err0;
    }

    if (pthread_attr_getdetachstate(&attr, &detachstate) != 0)
    {
        printf("getdetach state failed...\n");
        goto err0;
    }

    if (detachstate == PTHREAD_CREATE_JOINABLE)
        printf("PTHREAD_CREATE_JOINABLE\n");
    else
        printf("PTHREAD_CREATE_DETACHED\n");

    //等待线程结束
    if (pthread_join(tid, NULL) != 0)
        printf("分离的线程不能join成功....\n");

#if 0
    sleep(3);
    printf("3秒钟之后 线程处于不分离状态....\n");
    //设置线程分离属性 默认是不分离
    if (pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE) != 0)
    {
        printf("attr setdetachstate failed...\n");  
        goto err0;
    }

    //等待线程结束
    if (pthread_join(tid, NULL) != 0)
        printf("分离的线程不能join成功....\n");
    printf("此时线程处于joinable状态....\n");
#endif


    //销毁属性变量
    if (pthread_attr_destroy(&attr) != 0)
    {
        printf("pthread attr destroy failed...\n");
        goto err0;
    }

    return 0;
err0:
    return -1;
}


