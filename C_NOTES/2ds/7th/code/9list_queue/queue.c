#include "queue.h"



//创建队列头结点信息
queue_t *queue_create(int size, op_t my_destroy)
{
    queue_t *q = NULL;

    //分配空间
    q = malloc(sizeof(queue_t));
    if (NULL == q)
    {
        printf("malloc queue failed...\n"); 
        goto err0;
    }

    //初始化
    q->size = size;
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
    q->my_destroy = my_destroy;

	return q;
err0:
    return NULL;
}

//判断队列是否为空
int queue_is_empty(queue_t *q)
{
    //容错处理
    if (NULL == q)
    {
        printf("The queue is NULL\n"); 
        goto err0;
    }

    return (NULL == q->front);
err0:
    return -1;
}

//队列中元素的个数
int queue_count(queue_t *q)
{
    //容错处理
    if (NULL == q)
    {
        printf("The queue is NULl\n"); 
        goto err0;
    }

	return q->count;
err0:
    return -1;
}

//分配新结点
static node_t *_alloc_node(queue_t *q, void *data)
{
    node_t *new = NULL;

    //分配空间
    new = malloc(sizeof(node_t));
    if (NULL == new)
    {
        printf("malloc node failed..\n"); 
        goto err0;
    }
    memset(new, 0, sizeof(node_t));

    //分配数据域的空间
    new->data = malloc(q->size);
    if (NULL == new->data)
    {
        printf("malloc data failed...\n"); 
        goto err1;
    }
    memset(new->data, 0, q->size);

    //拷贝数据
    memcpy(new->data, data, q->size);

    new->next = NULL;


    return new;
err1:
    free(new);
err0:
    return NULL;
}



//入队列
int queue_en(queue_t *q, void *data)
{
    node_t *new = NULL;

    if (NULL == q)
        goto err0;

    //分配空间
    new = _alloc_node(q, data);
    if (NULL == new)
        goto err0;

    //相当于单链表的尾插
    if (NULL == q->front)
    {
        q->front = new; 
        q->rear = new;
    }
    else
    {
        q->rear->next = new; 
        //q->rear是指向队列的最后一个节点
        q->rear = new;
    }
    //队列的个数加1
    q->count++; 

	return 0;
err0:
    return -1;
}

//出队列
int queue_de(queue_t *q, void *data)
{
    node_t *tmp = NULL;
    //容错处理
    if (NULL == q || NULL == data)     
    {
        printf("q or data is NULL\n"); 
        goto err0;
    }

    //链表为空的情况
    if (queue_is_empty(q)) 
    {
        printf("The queue is empty....\n"); 
        goto err0;
    }

    tmp = q->front;

    q->front = tmp->next;
    memcpy(data, tmp->data, q->size);

    //释放节点空间
    if (NULL != q->my_destroy)
    {
        q->my_destroy(tmp->data); 
    }
    free(tmp->data);
    free(tmp);

    q->count --;

	return 0;
err0:
    return -1;
}
//返回队列中第一个元素的值
int queue_front(queue_t *q, void *data)
{
    //容错处理
    if (NULL == q || NULL == data)
    {
        printf("q or data is empty....\n"); 
        goto err0;
    }
    //拷贝数据
    memcpy(data, q->front->data, q->size);

	return 0;
err0:
    return -1;
}

//队列销毁
int queue_destroy(queue_t *q)
{
    node_t *tmp = NULL;

    while(NULL != q->front)
    {
        tmp = q->front->next; 

        if (NULL != q->my_destroy)
            q->my_destroy(q->front->data);

        free(q->front->data);
        free(q->front);
        
        q->front = tmp;
    }

    free(q);

	return 0;
}





