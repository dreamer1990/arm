#include "kernel_list.h"


//内核链表的尾插  带有头结点
int list_append(struct list_head *h, struct list_head *new)
{
    
    if (NULL == h || NULL == new)
    {
        printf("NULL pointer.....\n"); 
        goto err0;
    }
    
    new->next = h;
    new->prev = h->prev;

    h->prev->next = new;
    h->prev = new;

    return 0;
err0:
    return -1;
}


//内核链表的头插
int list_prepend(struct list_head *h, struct list_head *new)
{
    if (NULL == h || NULL == new) 
    {
        printf("NULL pointer....\n"); 
        goto err0;
    }

    //头插法
    new->next = h->next;
    new->prev = h;

    h->next->prev = new;
    h->next = new;

    return 0;
err0:
    return -1;
}


//内核链表的头插 第二个版本
int list_prepend_v1(struct list_head *h, struct list_head *new)
{
    list_append(h->next, new);
}



//内核链表的遍历
int list_traverse(struct list_head *h, op_t my_print)
{
    struct list_head *tmp = h->next;

    for (; tmp != h; tmp = tmp->next)
    {
        my_print(tmp); 
    }
    //换行
    putchar('\n');
}

//链表的销毁
int list_destroy(struct list_head *h, op_t my_destroy)
{
    struct list_head *tmp = h->next;
    struct list_head *save = NULL;

    for (; tmp != h; tmp = save)
    {
        save = tmp->next;
        my_destroy(tmp);  
    }

    return 0;
}




