#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define my_scanf(op,format,...)     do{     \
    int ret = 0;                            \
    ret = scanf(format, __VA_ARGS__);       \
    while('\n' != getchar())                \
        /*do nothing*/;                     \
    if (ret <= 0)                           \
        op;                                 \
}while(0)

//结点结构体
typedef struct _node_t{
    int n;                      //数据域
    struct _node_t *prev;       //前驱指针
    struct _node_t *next;       //后继指针
}node_t;

//尾插
int dlist_append(node_t** h, int data)
{
    node_t *new = NULL;
    node_t *tmp = *h;

    //为新结点分配空间
    new = malloc(sizeof(node_t));
    if (NULL == new)
    {
        printf("malloc failed....\n"); 
        goto err0;
    }

    memset(new, 0, sizeof(*new));
    //给新结点初始化
    new->n = data;

    //原来链表没有节点的情况
    if (NULL == tmp)
    {
        new->next = new;
        new->prev = new;
        //使*h指向链表的第一个节点
        *h = new;
    }
    else
    {
        //给new结点赋值 
        //new的后继指向链表的第一个节点
        new->next = tmp;
        //new的前驱指向原来链表的最后一个节点
        new->prev = tmp->prev;
        //原来最后一个节点的后继指针指向new 
        tmp->prev->next = new;
        //第一个节点的前驱指向new
        tmp->prev = new;
    
    }


    return 0;
err0:
    return -1;
}

//头插
int dlist_prepend(node_t** h, int data)
{
    
    node_t *new = NULL;
    node_t *tmp = *h;

    //新节点分配空间
    new = malloc(sizeof(node_t));
    if (NULL == new)
    {
        printf("The List is empty...\n"); 
        goto err0;
    }

    //新结点赋值
    new->n = data;
    
    //原来链表没有节点
    if (NULL == *h)
    {
        //只有一个节点的时候,前驱后继都指向本身
        new->next = new;
        new->prev = new;
    }
    else
    {
        //新结点的后继为原来链表的第一个节点
        new->next = tmp; 
        //新结点的前驱为原来链表的最后一个节点
        new->prev = tmp->prev;
        //原来最后一个节点的后继指向新节点
        tmp->prev->next = new;
        //原来第一个节点的前驱指向新节点
        tmp->prev = new;
    }

    //头指针指向新节点 新结点就是第一个节点
    *h = new;

    return 0;
err0:
    return -1;
}

//头插  第二个版本
int dlist_prepend_v2(node_t** h, int data)
{
    int ret = 0;
    //调用尾插方法 
    ret = dlist_append(h, data); 

    *h = (*h)->prev;
}


//链表的遍历
int dlist_traverse(node_t* h)
{
    node_t* tmp = h;

    //链表为空的情况
    if (NULL == h)
    {
        printf("list is empty....\n"); 
        goto err0;
    }

    //只能使用do while循环
    do{
        printf("%d  ", tmp->n); 
        tmp = tmp->next;
    }while(h != tmp);

    putchar('\n');

    return 0;
err0:
    return -1;
}

//链表的销毁
int dlist_destroy(node_t* h)
{
    node_t* save = NULL;
    node_t* tmp = NULL;

    //链表为空的情况
    if (NULL == h)
    {
        printf("链表为空...\n");
        goto err0;
    }

#if 0
    tmp = h->next;
    while(h != tmp)
    {
        save = tmp->next;
        free(tmp);
        tmp = save;
    }
    free(h);
#else
    tmp = h;
    do{
        //保存链表的下一个节点
        save = tmp->next;
        //释放当前节点的空间
        free(tmp);
        //使tmp指向下一个节点
        tmp = save;
    
    }while(h != tmp);
    
#endif

    return 0;
err0:
    return -1;
}

//无头双向循环链表
int main(void)
{
    int n;

    node_t* h = NULL;
    

    while(1)
    {
    retry:
        printf("please input a number[-1 quit]:   "); 
        my_scanf(goto retry, "%d", &n);
        if (-1 == n)
            break; 
        //尾插 
        //dlist_append(&h, n);
        //头插
        //dlist_prepend(&h, n);
        dlist_prepend_v2(&h, n);
    }
    //链表的遍历
    dlist_traverse(h);
    
    dlist_destroy(h);

    return 0;
}
