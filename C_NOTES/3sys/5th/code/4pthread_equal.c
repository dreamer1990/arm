#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
 *比较两个线程是否相等 不能直接用==
 *int pthread_equal(pthread_t t1, pthread_t t2);
 *功能: 判断两个线程是否为同一个线程
 *参数:
 *    t1  线程ID
 *    t2  线程ID
 *返回值:
 *    两个线程ID相同就返回非零
 *    否则返回0
 *
 */

void *fun(void *args)
{
    printf("New thread ID: %lu\n", pthread_self());
    printf("args ===> %s\n", (char *)args);
    //线程返回
    return (void*)NULL;
}

int main(void)
{
    pthread_t tid = -1;

    if (pthread_create(&tid, NULL, fun, "hello thread1") != 0) 
    {
        printf("创建线程失败...\n"); 
        goto err0;
    }
    //线程比较不建议使用== 或者 !=比较 可移植性差
    //if (tid != pthread_self())
    //比较两个线程ID是否相等 
    if (pthread_equal(pthread_self(), tid) == 0)
    {
        printf("两个线程不相等...\n"); 
    }
    else
        printf("两个线程相等....\n");

    sleep(2);

    return 0;
err0:
    return -1;
}
