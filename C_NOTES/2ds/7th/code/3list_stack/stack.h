#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void(*op_t)(void *data);

typedef struct _node_t{
    void *data;             //数据域
    struct _node_t *next;   //指针域
}node_t;

//栈的头结点信息
typedef struct _stack_t{

    node_t *top;        //栈顶指针
    int size;           //每个节点的大小
    int count;          //栈中的元素的个数
    op_t my_destroy;    //自定义销毁函数
}stack_t;


//创建栈信息结构体
stack_t *stack_create(int size, op_t my_destroy);

//判断是否为空栈
int stack_is_empty(stack_t *t);
//返回栈顶元素
int stack_top(stack_t *t, void *data);
//压栈
int stack_push(stack_t *t, void *data);
//出栈
int stack_pop(stack_t *t, void *data);
//销毁
int stack_destroy(stack_t *t);



#endif /*__STACK_H__*/
