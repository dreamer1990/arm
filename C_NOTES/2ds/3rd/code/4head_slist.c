#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define my_scanf(op, format, ...)   do{     \
    int ret = 0;                            \
    ret = scanf(format, __VA_ARGS__);       \
    while('\n' != getchar())                \
        /*do nothing*/;                     \
    if (ret <= 0)                           \
        op;                                 \
}while(0)


//结点的类型
typedef struct _stu {
    int data;           //数据域
    struct _stu* next;  //指针域
}stu_t;

//头插
int slist_prepend(stu_t *h, int data)
{
    stu_t *new = NULL; 

    //分配空间
    new = malloc(sizeof(stu_t)); 
    if (NULL == new)
    {
        printf("%s %d malloc failed...\n", __func__, __LINE__); 
        goto err0;
    }

    //给数据域赋值
    new -> data = data;
    //给指针域初始化,将链表的原来第一个结点作为第二个结点
    new -> next = h->next;

    //将新结点作为链表的第一个结点
    h->next = new;
    
    return 0;
err0:
    return -1;
}

//后插
int slist_append(stu_t *h, int data)
{
    stu_t *new = NULL;

    //分配空间
    new = malloc(sizeof(stu_t));
    if (NULL == new)
    {
        printf("%s %d malloc failed...\n", __func__, __LINE__); 
        goto err0;
    }

    //新结点赋值操作
    new -> data = data;
    new -> next = NULL;

    //将h指向链表的最后一个结点
    while(NULL != h -> next)
        h = h -> next;

    //将新结点插入到链表的结尾
    h -> next = new;

    return 0;
err0:
    return -1;
}


int slist_traverse(stu_t *h)
{
    //因为是有头的链表 有头的链表第一个结点没有放数据
    h = h -> next;

    //NULL代表链表结束
    while(NULL != h)
    {
        printf("%d  ", h -> data);
        //让h指向链表的下一个结点
        h = h -> next;
    }
    putchar('\n');
    return 0;
}

//销毁
int slist_destroy(stu_t *h)
{
    stu_t* tmp = NULL;

    tmp = h -> next;

    while(NULL != tmp)
    {
        //保存下一个结点
        h -> next = tmp -> next;
        //free掉当前结点
        free(tmp);
        //将tmp指向下一个结点 
        tmp = h -> next;
    }

    //将链表置空
    h -> next = NULL;

    return 0;
}

//有头单向不循环链表
int main(void)
{
    int n;

    //链表头结点初始化
    stu_t head = {
        .data = 0,
        .next = NULL,
    };

    //在链表中追加数据
    while(1)
    {
    retry:
        printf("please input a number[-1 quit]:  ");
        //获取一个整型数字
        my_scanf(goto retry, "%d", &n);

        if (-1 == n)
            break; 

        //头插
        //slist_prepend(&head, n);
        //尾插
        slist_append(&head, n);
    }
    //链表的遍历
    slist_traverse(&head);

    //链表的销毁
    slist_destroy(&head);

    return 0;
}


