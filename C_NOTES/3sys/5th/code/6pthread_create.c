#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *fun(void *s)
{
   printf("Thread s ===> %s\n", s); 

   return (void*)0;
}

//同一个进程中 线程ID都是唯一 但是在不同进程中 线程ID可能一样

int main(void)
{
    pid_t pid = -1;
    pthread_t tid1, tid2;

    pid = fork();
    //子进程
    if (pid == 0)
    {
       //创建一个线程 
        pthread_create(&tid1, NULL, fun, "Thread 1"); 
        printf("new thread id: %lu  main thread id: %lu\n", tid1, pthread_self());
        sleep(1);
        //子进程退出
        exit(0);    
    }
    //父进程
    pthread_create(&tid2, NULL, fun, "Thread 2");
    printf("new thread id: %lu  main thread id: %lu\n", tid2, pthread_self());
    //等待子进程退出
    wait(NULL);
    return 0;
}
