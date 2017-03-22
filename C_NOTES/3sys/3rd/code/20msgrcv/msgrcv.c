
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define SIZE 128
//key_t  int


#define MSG_EXCEPT      020000  /* recv any msg except of specified type.*/


//#define MSGMNB 16384   /* <= INT_MAX */   /* default max size of a message queue */

void show_msg(void *data)
{
    //输出消息类型
    printf("msg type: %ld\n", *(long *)data);
    //输出消息正文
    printf("msg: %s\n", (char *)(data + sizeof(long)));
}

int main(void)
{
    int ret = -1;
    int msgid = -1;
    char buf[SIZE] = {0};
    key_t  key = 0x55;

    //创建一个新的队列或者打开一个现存的消息队列
    msgid = msgget(key, IPC_CREAT | 0644); 
    if (-1 == msgid)
    {
        perror("msgid"); 
        goto err0;
    }
    system("ipcs -q");
    printf("msgid = %#x\n", msgid);

    memset(buf, 0, SIZE);
    //接收任意类型的消息 但是永远是消息队列中的第一个消息
    ret = msgrcv(msgid, buf, SIZE - sizeof(long), 0,  0);
    if (-1 == ret)
    {
        perror("msgrcv"); 
        goto err0;
    }

    printf("ret = %d\n", ret);
    show_msg(&buf);

    system("ipcs -q");

    return 0;
err0:
    return -1;
}









