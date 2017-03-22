#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define my_scanf(op, format, ...)   do{         \
        int ret = 0;                            \
        ret = scanf(format, __VA_ARGS__);       \
        while('\n' != getchar())                \
            /*do nothing*/;                     \
        if (ret <= 0)                           \
            op;                                 \
}while(0)

typedef struct _node_t {
    int id;                 //学号
    char sex;               //性别
    char name[32];          //名字
    struct _node_t *next;   //指针域
}node_t;

//链表的头插
int slist_prepend(node_t *h, int id)
{
    node_t *new = NULL;

    //分配空间
    new = malloc(sizeof(node_t));
    memset(new, 0, sizeof(node_t));
    if (NULL == new)
    {
        printf("%s  %d malloc failed...\n", __func__, __LINE__); 
        goto err0;
    }

    //结点赋值
    new -> id = id;
    new -> sex = "MF"[random() % 2];
    sprintf(new -> name, "%c%c%c%c%c%c", 'A' + random() % 26, 'a' + random() % 26,
                                         'a' + random() % 26, 'A' + random() % 26,
                                         'a' + random() % 26, 'a' + random() % 26);
    new->next = NULL;
    //前插
    new -> next = h -> next;
    h -> next = new;

    return 0;
err0:
    return -1;
}

//尾插
int slist_append(node_t *h, int id)
{
    node_t *new = NULL;

    //分配空间
    new = malloc(sizeof(node_t));
    if (NULL == new)
    {
        printf("%s  %d malloc failed..\n", __func__, __LINE__); 
        goto err0;
    }

    //新的结点的初始化
    new->id = id;
    new->sex = "MF"[random() % 2];
    sprintf(new -> name, "%c%c%c%c%c%c", 'A' + random() % 26, 'a' + random() % 26,
                                         'a' + random() % 26, 'A' + random() % 26,
                                         'a' + random() % 26, 'a' + random() % 26);
    new->next = NULL;

    //尾插 
    while(NULL != h->next)
        h = h->next;
    h->next = new;

    return 0;
err0:
    return -1;
}

//链表的遍历
int slist_traverse(node_t *h)
{
    //有头的链表 第一个结点是h->next
    h = h -> next;

    //如果该结点为NULL,链表结束
    while(NULL != h)
    {
        printf("id: %d  sex:  %c name: %s\n", h -> id, h -> sex, h -> name); 
        //h指向下一个结点
        h = h -> next;
    }
    return 0;
}

//链表的销毁
int slist_destroy(node_t *h)
{
    node_t *save = NULL;

    //h指向第一个结点
    h = h->next;

    while(h)
    {
        //保存下一个结点
        save = h->next;
        //释放空间
        free(h);
        h = save;
    }

    return 0;
}

int main(void)
{
    int id;
    node_t head = {
        .next = NULL, 
    };

    //设置随机种子
    srandom(time(NULL));

    while(1)
    {
    retry:
        printf("please input a number[-1 quit]:  ");
        my_scanf(goto retry, "%d", &id);

        if (-1 == id)
            break;

        //前插
        //slist_prepend(&head, id);
        //尾插
        slist_append(&head, id);
    }

    //链表的遍历
    slist_traverse(&head);
    //链表的销毁
    slist_destroy(&head);

    return 0;
}
