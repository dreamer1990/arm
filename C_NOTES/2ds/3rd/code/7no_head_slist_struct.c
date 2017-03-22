#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define my_scanf(op, format, ...)   do{         \
    int ret = 0;                                \
    ret = scanf(format, __VA_ARGS__);           \
    while('\n' != getchar())                    \
        /*do nothing*/;                         \
    if (ret <= 0)                               \
        op;                                     \
}while(0)

//学生信息结构体
struct stu_t {
    int id;         //学号
    char sex;       //性别
    char name[32];  //姓名
};

//链表结点结构体
typedef struct _node_t {
    struct stu_t stu;       //数据域
    struct _node_t* next;   //指针域
}node_t;

//头插 没有头指针
int slist_prepend(node_t **h, int id)
{
    //新结点指针
    node_t *new = NULL;
    //a. 分配内存
    new =  malloc(sizeof(node_t));
    if (NULL == new)
    {
        printf("%s  %d malloc failed..\n", __func__, __LINE__); 
        goto err0;
    }

    //b. 初始化结点
    new->stu.id = id;
    new->stu.sex = "MF"[random() % 2];
    sprintf(new->stu.name, "%c%c%c%c%c%c%c%c", 'A' + random() % 26, 'a' + random() % 26,
                                               'a' + random() % 26, 'a' + random() % 26,
                                               'a' + random() % 26, 'A' + random() % 26,
                                               'a' + random() % 26, 'a' + random() % 26
    );
    new->next = *h;

    //c. 插入新结点  头插

    *h = new;
    
    return 0;
err0:
    return -1;
}

int slist_append(node_t **h, int id)
{
    //新结点指针
    node_t *new = NULL;
    node_t *tmp = NULL;

    //a. 分配内存
    new =  malloc(sizeof(node_t));
    if (NULL == new)
    {
        printf("%s  %d malloc failed..\n", __func__, __LINE__); 
        goto err0;
    }

    //b. 初始化结点
    new->stu.id = id;
    new->stu.sex = "MF"[random() % 2];
    sprintf(new->stu.name, "%c%c%c%c%c%c%c%c", 'A' + random() % 26, 'a' + random() % 26,
                                               'a' + random() % 26, 'a' + random() % 26,
                                               'a' + random() % 26, 'A' + random() % 26,
                                               'a' + random() % 26, 'a' + random() % 26
    );

    new->next = NULL;

    tmp = *h; 
    if (NULL == *h)
    {
        *h = new; 
    }
    else
    {
        while(NULL != tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }

    return 0;
err0:
    return -1;
}


//链表的遍历
int slist_traverse(node_t* h)
{
    //h = h->next;

    //循环 打印链表中所有的结点
    while(h)
    {
        printf("id: %d char: %c name: %s\n", h->stu.id, h->stu.sex, h->stu.name); 
        h = h->next;
    }

    return 0;
}

//链表的销毁
int slist_destroy(node_t* h)
{
    node_t *save = NULL;
    while(h)
    {
        save = h->next;
        free(h);
        h = save;
    }

    return 0;
}

int main(void)
{
    int id;
    node_t *head = NULL;

    srandom(time(NULL));

    while(1)
    {
    retry:
        printf("please input a number[-1 quit]:   ");
        my_scanf(goto retry, "%d", &id);

        if (-1 == id)
            break;
        //头插
        //slist_prepend(&head, id);
        //尾插
        slist_append(&head, id);
    }
    
    //链表的遍历
    slist_traverse(head);
    //链表的销毁
    slist_destroy(head);

    return 0;
}



