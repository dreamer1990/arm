#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void(*op_t)(void *data);

typedef struct _queue_t{
    void *data; //数组的首地址
    int size;   //队列中元素的大小
    int max;    //队列的最大值
    int front;  //队头索引
    int rear;   //队尾索引
    op_t my_destroy;
}queue_t;

//创建队列头结点信息
queue_t *queue_create(int size, int len, op_t my_destroy);

//判断队列是否为空
int queue_is_empty(queue_t *q);
//判断队列是否为满
int queue_is_full(queue_t *q);

//队列中元素的个数
int queue_count(queue_t *q);
//入队列
int queue_en(queue_t *q, void *data);
//出队列
int queue_de(queue_t *q, void *data);
//返回队列中第一个元素的值
int queue_front(queue_t *q, void *data);
//队列销毁
int queue_destroy(queue_t *q);

#endif /*__QUEUE_H__*/
