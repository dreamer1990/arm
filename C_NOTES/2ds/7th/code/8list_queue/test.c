#include "queue.h"

#define MY_SCANF(op,format, ...)        do{     \
    int ret = 0;                                \
    ret = scanf(format, __VA_ARGS__);           \
    while('\n' != getchar())                    \
        /*do nothing*/;                         \
    if (ret <= 0)                               \
        op;                                     \
}while(0)


int main(void)
{
    int id = 0;
    queue_t *q = NULL; 

    //分配空间
    q = queue_create(sizeof(int),  NULL);
    if (NULL == q)
        goto err0;

    while(1)
    {
    retry:
        printf("please inputa an id[-1 quit]:   "); 
        MY_SCANF(goto retry, "%d", &id);

        //退出循环
        if (-1 == id)
            break;

        //入队列 
        queue_en(q, &id); 
    }

    printf("队列中元素的个数: %d\n", queue_count(q));

    //出队列
    while(!queue_is_empty(q))
    {
        memset(&id, 0, sizeof(id)); 
        queue_de(q, &id); 
        printf("id:  %d\n", id);
    }


    queue_destroy(q);


    return 0;
err0:
    return -1;
}
