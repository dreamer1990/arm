
#include "queue.h"

//创建队列头结点信息
queue_t *queue_create(int size, int len, op_t my_destroy)
{
    queue_t *q = NULL;

    //容错检查
    if (len == 0 || 0 == size)
    {
        printf("len or size is invalid\n"); 
        goto err0;
    }

    //分配空间
    q = malloc(sizeof(queue_t));
    if (NULL == q)
    {
        printf("malloc queue_t failed...\n"); 
        goto err0;
    }

    //初始化
    q->data = malloc(size * (len + 1));
    if (NULL == q->data)
    {
        printf("malloc q->data failed....\n"); 
        goto err1;
    }
    memset(q->data, 0, size * (len + 1));

    q->size = size;
    q->max = len + 1;
    q->front = 0;
    q->rear = 0;
    q->my_destroy = my_destroy;

    return q;
err1:
    free(q);
err0:
	return NULL;
}

//判断队列是否为空
int queue_is_empty(queue_t *q)
{
    if (NULL == q)
        goto err0 ;
    //队列为空的条件
	return  q->front == q->rear;
err0:
    return -1;
}
//判断队列是否为满
int queue_is_full(queue_t *q)
{
    if (NULL == q)
        goto err0;
    //队列满的条件
    return (q->rear + 1) % q->max == q->front;
err0:
    return -1;
}

//队列中元素的个数
int queue_count(queue_t *q)
{
    if (NULL == q)
        goto err0;
    //队列的长度 
    return (q->rear - q->front + q->max) % q->max;
err0:
    return -1;
}
//入队列
int queue_en(queue_t *q, void *data)
{
    //出错的情况
    if (NULL == q || NULL == data)
    {
        printf("The queue is NULL\n");
        goto err0; 
    }

    //如果队列是满  则入队列失败
    if (queue_is_full(q))
    {
        printf("The queue is full\n"); 
        goto err0;
    }

    //拷贝数据
    memcpy(q->data + q->size * q->rear, data, q->size);

    //改变队尾索引的值
    q->rear = (q->rear + 1) % q->max;
    
	return 0;
err0:
    return -1;
}

//出队列
int queue_de(queue_t *q, void *data)
{
    //容错处理
    if (NULL == q || NULL == data)
    {
        printf("The q or data is NULL\n"); 
        goto err0;
    }

    //队列为空的情况
    if (queue_is_empty(q))
    {
        printf("The queue is empty...\n"); 
        goto err0;
    }
    //拷贝数据
    memcpy(data, q->data + q->size * q->front, q->size);
    //改变对头索引
    q->front = (q->front + 1) % q->max;

	return 0;
err0:
    return -1;
}
//返回队列中第一个元素的值
int queue_front(queue_t *q, void *data)
{
    if(NULL == q || NULL == data)
        goto err0;

    if (queue_is_empty(q))
        goto err0;

    //将队列的第一个元素赋值给data
    memcpy(data, q->data, q->size);

	return 0;
err0:
    return -1;
}
//队列销毁
int queue_destroy(queue_t *q)
{
    int i = 0;

    if (NULL == q)
        goto err0;

    if (NULL != q->my_destroy)
    {
        for (i = 0; i < q->max; i++)
        {
            q->my_destroy(q->data + q->size * i);
        }
    }

    free(q->data);
    free(q);

	return 0;
err0:
    return -1;
}







