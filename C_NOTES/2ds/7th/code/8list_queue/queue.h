#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void(*op_t)(void *data);

//节点结构体
typedef struct _node_t {
    void *data;
    struct _node_t *next;
}node_t;

typedef struct _queue_t{
    int size;       //节点数据域的大小
    int count;      //队列中元素的个数

    node_t *front;  //队列对头指针 
    node_t *rear;   //队列队尾指针

    op_t my_destroy;//自定义销毁函数
}queue_t;



//创建队列头结点信息
queue_t *queue_create(int size, op_t my_destroy);

//判断队列是否为空
int queue_is_empty(queue_t *q);

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
