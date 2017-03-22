#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

//线程属性变量
pthread_attr_t attr; 



void *fun(void *args)
{

    void *stackaddr = NULL;
    size_t stacksize = -1;


    //获取栈的基址和栈的大小
    if (pthread_attr_getstack(&attr, &stackaddr, &stacksize) != 0)
    {
        printf("get stack failed...\n"); 
        goto err0;
    }

    printf("stackaddr = %p   stacksize: %lu\n", stackaddr, stacksize);

    return (void *)0;
err0:
    return (void *)-1;
}

int main(void)
{
    pthread_t tid;

    //初始化线程属性变量
    if (pthread_attr_init(&attr) != 0)
    {
        printf("pthread attr init failed...\n"); 
        goto err0;
    }

    if (pthread_attr_setstack(&attr, (void*)0x40197000, 1024) != 0)
    {
        printf("attr setstack failed...\n"); 
    }

    pthread_create(&tid, &attr, fun, NULL);

    pthread_join(tid, NULL);
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


