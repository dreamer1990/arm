#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

//自定义清理函数
void cleanup(void *data)
{
    printf("clean up data: %s\n", (char*)data);
}

void *fun1(void *args)
{

    int *p = malloc(4);
    memset(p, 0, 4);
    printf("thread id: %lu  args: %s\n", pthread_self(), (char*)args);
    //push和pop一定要配对使用  因为他们都是宏实现的 do{        }while(0)
    pthread_cleanup_push(cleanup, "hello 1");
    pthread_cleanup_push(cleanup, "hello 2");
    pthread_cleanup_push(free, p);

    pthread_cleanup_pop(1);
    pthread_cleanup_pop(2);
    pthread_cleanup_pop(3);

    pthread_exit((void*)0x1);
}

void *fun2(void *args)
{
    printf("thread id: %lu  args: %s\n", pthread_self(), (char*)args);
    //先进后除  pop顺序与push相反
    pthread_cleanup_push(cleanup, "uplooking 1");
    pthread_cleanup_push(cleanup, "uplooking 2");
    //如果参数指定为0 那么出栈的时候不会调用
    pthread_cleanup_pop(1);
    pthread_cleanup_pop(2);

    pthread_exit((void*)0x2);
}

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


    return 0;
}

