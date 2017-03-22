#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//容错宏 防止出现获取输入的值失败
#define my_scanf(op, format, ...)   do{     \
    int ret = 0;                            \
    ret = scanf(format, __VA_ARGS__);       \
    while('\n' != getchar())                \
    /*do nothing*/;                     \
    if (ret <= 0)                           \
    op;                                 \
}while(0)

//无头单链表

//单链表结点类型
typedef struct _stu {
    int id;             //数据域
    struct _stu* next;  //指针域
}stu_t;


//头插
int slist_prepend(stu_t **h, int data)
{
    stu_t *new = NULL; 

    //分配空间
    new = malloc(sizeof(stu_t));
    if (NULL == new)
        goto err0;

    //给数据域赋值
    new -> id = data;
    //给指针域赋值
    new -> next = *h;

    //使*h指向新的第一个结点
    *h = new;

    return 0;
err0:
    return -1;
}

//尾插
int slist_append(stu_t **h, int data)
{
    stu_t *head = NULL;
    stu_t *new = NULL;

    head = *h;

    //分配一个结点的空间  新结点
    new = malloc(sizeof(stu_t));
    if (NULL == new)
    {
        printf("%s %d malloc failed..\n", __func__, __LINE__); 
        goto err0;
    }
    //给结点数据域赋值
    new -> id = data;
    new -> next = NULL;

    //该链表没有一个结点的时候
    //if (NULL == head)
    if (NULL == *h)
    {
        *h = new;
        //head = new; 
    }
    else
    {

        //将head指向该链表的最后一个结点
        while(NULL != head->next)
        {
            head = head->next; 
        }
        //将新结点插入到该链表的尾部
        head->next = new;
    }

    return 0;
err0:
    return -1;
}

//链表的遍历
int slist_traverse(stu_t *h)
{
    while(NULL != h)
    {
        //访问数据域
        printf("%d  ", h->id); 
        
        //h指向下一个结点
        h = h -> next;
    }
    putchar('\n');

    return 0;
}

int slist_destroy(stu_t *h)
{
    stu_t *tmp = NULL;

    while(NULL != h)
    {
        //将该链表的下一个结点保存
        tmp = h->next; 
        //释放结点的空间
        free(h);
        //h指向下一个结点
        h = tmp;
    }

    return 0;
}

//无头无序不循环单链表
int main(void)
{
    int n;

    stu_t *head = NULL;

    while(1)
    {
    retry: 
        printf("please input a number[-1 quit]:   "); 
        my_scanf(goto retry, "%d", &n);
        //退出循环
        if (-1 == n)
            break;
        //slist_append(&head, n); 
        slist_prepend(&head, n);
    }

    slist_traverse(head);

    slist_destroy(head);
    //将head指向NULL
    head = NULL;

    return 0;
}


