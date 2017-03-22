#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct _stu_t{
    int id;
    char sex;
    char name[32];
}stu_t;


/*
 *
 *int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
 *        void *(*start_routine) (void *), void *arg);
 *功能:创建一个线程
 *参数:
 *    thread 返回新建线程ID
 *    attr   设置线程的属性
 *    start_routile  线程创建之后 执行的函数
 *    arg    回调函数的参数
 *返回值:
 *    成功 0
 *    失败 错误号
 */

//如果进程退出 则所有的线程都会退出

//新建线程后开始执行的函数
void *fun(void *args)
{
    printf("New thread ID: %lu\n", pthread_self());

    printf("args = %s\n", (char*)args);

    //如果main返回后 则该新建的线程也会退出
    while(1)
    {
        printf("do work ...\n"); 
        sleep(1);
    }
    
    return (void*)0;
}

void *fun2(void *args)
{
    stu_t *p = args;

    printf("New Thread2 ID: %lu\n", pthread_self());
    printf("args id: %d sex: %c name: %s\n", p->id, p->sex, p->name);

    return (void*)0;
}

int main(void)
{
    int ret = -1;
    pthread_t tid = -1;
    pthread_t tid2 = -1;

    stu_t stu = {
        .id = 33,
        .sex = 'M',
        .name = "uplooking",
    };

    printf("Main thread ID: %lu\n", pthread_self());

    //如果属性指定NULL 则表示默认的属性 
    ret = pthread_create(&tid, NULL, fun, "hello world");
    if (0 != ret)
    {
        printf("pthread_create failed...\n"); 
        goto err0;
    }
    //创建第二个线程
    ret = pthread_create(&tid2, NULL, fun2, &stu);
    if (ret != 0)
    {
        printf("创建线程失败...\n"); 
        goto err0;
    }

    sleep(5);

    return 0;
err0:
    return -1;
}









