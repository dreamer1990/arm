#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

//int pthread_key_create(pthread_key_t *key, void (*destructor)(void*));
//void *pthread_getspecific(pthread_key_t key);
//int pthread_setspecific(pthread_key_t key, const void *value);

typedef struct _s_t{
    int a;
    int b;
    char c;
    char name[32];
}s_t;

pthread_key_t key;

//自定义清理函数
void cleanup(void *data)
{
    printf("destructor.....\n");
}

void *fun1(void *args)
{
    int i = 100;
    printf("thread id: %lu  args: %s\n", pthread_self(), (char*)args);

    pthread_setspecific(key, &i);
    
    printf("key = %d\n", *(int *)pthread_getspecific(key));

    pthread_exit((void*)0x1);
}

void *fun2(void *args)
{
    printf("thread id: %lu  args: %s\n", pthread_self(), (char*)args);
    s_t stu = {
        .a = 1,
        .b = 2,
        .c = 'M',
        .name = "uplooking",
    }, *p = NULL;

    pthread_setspecific(key, &stu);
    
    p = pthread_getspecific(key);

    printf("a: %d b: %d c: %c name: %s\n", p->a, p->b, p->c, p->name);

    pthread_exit((void*)0x2);
}


int main(void)
{
    void *val = NULL;
    pthread_t tid[2];

    //创建一个关联的键值
    pthread_key_create(&key, cleanup);
    
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
    
    //删除key
    pthread_key_delete(key);

    return 0;
}

