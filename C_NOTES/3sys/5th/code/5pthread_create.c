#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int val = 88;


void *fun1(void *args)
{
    //num存放在自己私有的线程栈上
    int num = 88;
    val++;
    printf("New thread ID: %lu\n", pthread_self());
    printf("args ===> %s val = %d num = %d\n", (char *)args, val, num);
    //线程返回
    return (void*)NULL;
}

void *fun2(void *args)
{
    int num = 89;
    printf("New thread ID: %lu\n", pthread_self());
    printf("args ===> %s val = %d num = %d\n", (char *)args, val, num);
    //线程返回
    return (void*)NULL;
}
int main(void)
{
    pthread_t tid = -1;
    pthread_t tid2 = -1;


    //创建第二个线程
    pthread_create(&tid2, NULL, fun2, "hello thread2");

    if (pthread_create(&tid, NULL, fun1, "hello thread1") != 0) 
    {
        printf("创建线程失败...\n"); 
        goto err0;
    }

    sleep(3);

    return 0;
err0:
    return -1;
}
