
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define SIZE 128

//key_t  int

//#define MSGMNB 16384   /* <= INT_MAX */   /* default max size of a message queue */

int main(void)
{
    int ret = -1;
    int msgid = -1;
    int type;
    key_t  key = 0x55;
    char buf[SIZE];

    printf("long:  %d\n", sizeof(long));

    //创建一个新的队列或者打开一个现存的消息队列
    msgid = msgget(key, IPC_CREAT | 0644); 
    if (-1 == msgid)
    {
        perror("msgid"); 
        goto err0;
    }
    system("ipcs -q");
    printf("msgid = %#x\n", msgid);

    printf("please input a msg type:  ");
    scanf("%d", &type);

    memset(buf, 0, SIZE);
    //类型
    *(long*)buf = type;
    memcpy(buf + sizeof(long), "hello world", strlen("hello world"));

    //标志默认值  默认值是阻塞类型 
    ret = msgsnd(msgid, buf, 32 - sizeof(long), 0);
    if (ret < 0)
    {
        perror("msgsnd");    
        goto err0;
    }

    system("ipcs -q");

    return 0;
err0:
    return -1;
}









