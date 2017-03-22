#include "stack.h"


//创建栈的信息结构体
stack_t *stack_create(int size, int max, op_t my_destroy)
{
    stack_t *t = NULL;

    //分配空间
    t = malloc(sizeof(stack_t));
    if (NULL == t)
    {
        printf("malloc stack failed...\n"); 
        goto err0;
    }
    memset(t, 0, sizeof(*t));

    //初始化
    t->size = size;
    t->max = max;
    t->top = 0;
    t->my_destroy = my_destroy;

    //分配空间
    t->p = malloc(size * max);
    if (NULL == t->p)
    {
        printf("malloc p failed...\n"); 
        goto err1;
    }
    memset(t->p, 0, t->size * t->max);

    return t;
err1:
    free(t);
err0:
    return NULL;
}

//判断栈是否为空
int stack_is_empty(stack_t *t)
{
	return 0 == t->top;
}

//判断栈是否满
int stack_is_full(stack_t *t)
{
    return t->max == t->top;
}

//压栈
int stack_push(stack_t *t, void *data)
{
    if (stack_is_full(t))
    {
        printf("The stack is full...\n"); 
        goto err0;
    }

    memcpy(t->p + t->size * t->top, data, t->size);
    t->top ++;

	return 0;
err0:
    return -1;
}
//出栈
int stack_pop(stack_t *t, void *data)
{
    if (stack_is_empty(t))
    {
        printf("The stack is empty....\n"); 
        goto err0;
    }

    memcpy(data, t->p + t->size * (t->top - 1), t->size);
    t->top --;

	return 0;
err0:
    return -1;
}
//获取栈顶的元素
int stack_top(stack_t *t, void *data)
{
    memcpy(data, t->p + t->size * (t->top - 1), t->size);

	return 0;
}

//将栈一次性清空
int stack_clear(stack_t *t)
{
    memset(t->p, 0, t->size * t->max);
    t->top = 0;

	return 0;
}

//栈的销毁
int stack_destroy(stack_t *t)
{
    while(!stack_is_empty(t))
    {
        if (NULL != t->my_destroy)
        {
            t->my_destroy(t->p + t->size * (--t->top)); 
        }
    }

    free(t->p); 
    free(t);

	return 0;
err0:
    return -1;
}


