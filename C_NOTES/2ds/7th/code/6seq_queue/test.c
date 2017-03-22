#include "queue.h"



int main(void)
{
    int i = 0;
    int n = 0;

    queue_t *q = NULL;

    q = queue_create(sizeof(int), 10, NULL);
    if (NULL == q)
        goto err0;


    //入队列
    for (i = 1; i < 11; i++)
    {
        queue_en(q, &i);
    }

    //返回队列第一个元素
    queue_front(q, &n);
    printf("队列首元素是:  %d\n", n);

    printf("出队列的顺序为:  ");
    while(!queue_is_empty(q))
    {
        queue_de(q, &n); 

        printf("%d  ", n);
    }
    putchar('\n');

    queue_destroy(q);

    return 0;
err0:
    return -1;
}
