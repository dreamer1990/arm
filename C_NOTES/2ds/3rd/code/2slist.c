#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//单链表的节点元素
struct stu_t {
    int data;           //数据域: 用来存放数据
    struct stu_t *next; //指针域: 用来保存下一个节点的地址 如果是最后一个节点保存NULL
};

int main(void)
{
    int n;
    struct stu_t *p = NULL;
    struct stu_t *new = NULL;

    while(1)
    {
        printf("please input a number[-1 quit]:   "); 
        scanf("%d", &n);

        if (-1 == n)
        {
            //退出循环
            break; 
        }

        //分配一个结点的内存空间
        new = malloc(sizeof(struct stu_t));
        if (NULL == new)
        {
            printf("malloc failed...\n"); 
            goto err0;
        }

        //给数据域赋值
        new->data = n;
        new->next = p;

        p = new;
    }

    //遍历:遍历链表中数据域部分的数据
    while(NULL != new)
    {
        printf("%d  ", new->data); 

        //将new指向该结点的下一个结点
        new = new->next;
    }
    putchar('\n');

    //释放内存空间
    new = p;
    while(NULL != new)
    {
        //保存该链表的下一个结点 
        p = new->next;
        free(new);
        new = p;
    }

    return 0;
err0:
    //释放已经分配的内存
    return -1;
}
