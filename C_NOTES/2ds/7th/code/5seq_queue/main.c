#include <stdio.h>

#define MAX 10

int a[MAX + 1];
//指向队列的第一个元素
int front = 0;  
//指向队列的最后一个元素的下一个位置
int rear = 0;

//判断队列是否为空
int queue_is_empty(void)
{
    return front == rear;
}

//判断队列是否为满
int queue_is_full(void)
{
    //判断队列为满的情况
    return (rear + 1) % (MAX + 1) == front;
}
//返回队列中元素的个数
int queue_count(void)
{
    return (rear - front + MAX + 1) % (MAX + 1);
}

//入队列
int queue_en(int n)
{
    //入队列判断是否为满
    if (queue_is_full())
        goto err0;
    
    a[rear]= n;
    rear = (rear + 1) % (MAX + 1);

    return 0;
err0:
    return -1;
}

//出队列
int queue_de(void)
{
    int ret = 0;
    //出队列时队列不能为空
    if (queue_is_empty())
        goto err0;
    
    ret = a[front];
    front = (front + 1) % (MAX + 1);

    return ret; 
    
err0:
    return -1;
}

//返回队列中第一个元素
int queue_front(void)
{
    return a[front];
}


int main(void)
{
    int i = 0;

    //入队列
    for (i = 0; i < 20; i++ )
    {
        queue_en(i + 1); 
    }

#if 0
    //出队列
    for (i = 0; i < 10; i++)
    {
        printf("%d  ", queue_de()); 
    }
#endif 

    printf(" --> %d\n", queue_de());

    queue_en(88);

    printf("count:   %d\n", queue_count());

    printf("-----> %d\n", queue_front());

    while(!queue_is_empty())
    {
        printf("%d  ", queue_de()); 
    }
    putchar('\n');


    return 0;
}



