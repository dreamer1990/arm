#include "stack.h"



//创建栈信息结构体
stack_t *stack_create(int size, op_t my_destroy)
{
    //分配空间
    stack_t *t = malloc(sizeof(stack_t));
    if (NULL == t)
    {
        printf("malloc failed...\n"); 
        goto err0;
    }

    //初始化
    t->top = NULL;
    t->size = size;
    t->count = 0;
    t->my_destroy = my_destroy;

	return t;
err0:
    return NULL;
}

//判断是否为空栈
int stack_is_empty(stack_t *t)
{
	return NULL == t->top;
}

//返回栈顶元素
int stack_top(stack_t *t, void *data)
{
    if (NULL == t || NULL == t->top)
    {
        printf("The stack has no element....\n");
        goto err0;
    }
    memcpy(data, t->top->data, t->size);

	return 0;
err0:
    return -1;
}

//分配新结点
static node_t* _alloc_node(stack_t *t, void *data)
{
    node_t *new = NULL;
    if (NULL == t || NULL == data)
    {
        printf("error.....\n"); 
        goto err0;
    }

    //分配空间
    new = malloc(sizeof(node_t));
    if (NULL == new)
    {
        printf("malloc node failed...\n");
        goto err0; 
    }
    memset(new, 0, sizeof(node_t));

    //分配数据域的空间
    new->data = malloc(t->size);
    if (NULL == new->data)
    {
        printf("malloc data failed....\n"); 
        goto err1;
    }
    memset(new->data, 0, t->size);

    //拷贝数据
    memcpy(new->data, data, t->size);

    return new;
err1:
    free(new);
err0:
    return NULL;
}
//压栈
int stack_push(stack_t *t, void *data)
{
    node_t *new = NULL;

    new = _alloc_node(t, data);
    if (NULL == new)
        goto err0;
    //头插
    new->next = t->top;
    t->top = new;

    t->count ++;

	return 0;
err0:
    return -1;
}
//出栈
int stack_pop(stack_t *t, void *data)
{
    node_t *tmp = NULL; 

    tmp = t->top;
    memcpy(data, tmp->data, t->size);
    t->top = tmp->next;

    free(tmp->data);
    free(tmp);
    t->count --;
	return 0;
}
//销毁
int stack_destroy(stack_t *t)
{
    node_t *tmp = NULL;

    while(NULL != t->top)
    {
        tmp = t->top;

        t->top = tmp->next;
        if (NULL != t->my_destroy)
        {
            t->my_destroy(tmp->data);
        }

        free(tmp->data);
        free(tmp);
    }

    free(t);

	return 0;
}

