#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void(*op_t)(void *data);

typedef struct _stack_t{
    void *p;            //数据域
    int size;           //数据的大小
    int max;            //栈的最大容量
    int top;            //栈顶游标
    
    op_t my_destroy;    //自定义销毁函数

}stack_t;

//创建栈的信息结构体
stack_t *stack_create(int size, int max, op_t my_destroy);

//判断栈是否为空
int stack_is_empty(stack_t *t);

//判断栈是否满
int stack_is_full(stack_t *t);

//压栈
int stack_push(stack_t *t, void *data);
//出栈
int stack_pop(stack_t *t, void *data);
//获取栈顶的元素
int stack_top(stack_t *t, void *data);

//将栈一次性清空
int stack_clear(stack_t *t);

//栈的销毁
int stack_destroy(stack_t *t);



#endif /*__STACK_H__*/
