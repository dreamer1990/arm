#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define  my_scanf(op,format,...)    do{     \
    int ret = 0;                            \
    ret = scanf(format, __VA_ARGS__);       \
    while('\n' != getchar())                \
        /*do nothing*/;                     \
    if (ret <= 0)                           \
        op;                                 \
}while(0)


typedef struct _node_t {
    int n;                  //数据域
    struct _node_t *prev;    //前驱指针
    struct _node_t *next;    //后继指针

}node_t;


//尾插
int dlist_append(node_t *h, int data)
{
    //新结点指针
    node_t *new = NULL;

    //分配内存
    new = malloc(sizeof(node_t));
    if (NULL == new)
    {
        printf("malloc failed...\n");
        goto err0;
    }

    new->n = data; 

    //先给new结点赋值
    new->next = h;
    new->prev = h->prev;

    h->prev->next = new;
    h->prev = new;


err0:
    return -1;
}

//头插
int dlist_prepend(node_t *h, int data)
{
    node_t *new = NULL;

    //分配空间
    new = malloc(sizeof(node_t));
    if (NULL == new)
    {
        printf("malloc failed...\n"); 
        goto err0;
    }

    //new相关成员赋值
    new->n = data;

    
    new->next = h->next;
    new->prev = h;

    h->next->prev = new;
    h->next = new;


    return 0;
err0:
    return -1;
}

int dlist_traverse(node_t *h)
{
    node_t *tmp = h->next;
    
    //h是头结点指针 没有放任何数据
    while(h != tmp)
    {
        printf("%d  ", tmp->n); 
        tmp = tmp->next;
    }
    //换行
    putchar('\n');
    
    return 0;
}

int dlist_destroy(node_t *h)
{
    //tmp指向第一个节点
    node_t *tmp = h->next;
    node_t *save = NULL;

    while(h != tmp)
    {
        //保存下一个节点
        save = tmp->next;

        //释放内存
        free(tmp); 
        tmp = NULL;

        tmp = save;
    }


    return 0;
}

//有头双向循环链表
int main(void)
{
    int n = 0;

    //初始化头结点
    node_t h = {
        .n = 0,
        .prev = &h,
        .next = &h,
    };


    while(1)
    {
    retry:
        printf("please input a number[-1 quit]:     ");
        my_scanf(goto retry, "%d", &n);
        //退出循环
        if (-1 == n)
            break;
        //尾插 
        //dlist_append(&h, n);
        //头插
        dlist_prepend(&h, n);
    }

    //遍历双向循环链表
    dlist_traverse(&h);
    //销毁链表
    dlist_destroy(&h);
    return 0;
}
