
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

//key_t  int


//#define MSGMNB 16384   /* <= INT_MAX */   /* default max size of a message queue */

//声明一个结构体类型
typedef struct _stu_t{
    int id;
    char sex;
    char name[32];
}stu_t;

//消息结构体
struct msgbuf {
    long mtype; //消息类型  必须大于0
    stu_t stu;  //消息正文
};


void create_msg(void *data, int type)
{
    struct msgbuf* p = data;

    p->mtype = type;
    p->stu.id = random() % 100;
    p->stu.sex = "MF"[random() % 2];
    strcpy(p->stu.name, "uplooking");
}
void show_msg(void *data)
{
    struct msgbuf* p = data;
    //输出消息类型
    printf("msg type: %ld\n", p->mtype);
    //输出消息正文
    printf("id: %d sex: %c name: %s\n", p->stu.id, p->stu.sex, p->stu.name);
}

int main(void)
{
    int ret = -1;
    int msgid = -1;
    int type;
    key_t  key = 0x55;

    struct msgbuf msg;

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

    //创建消息
    create_msg(&msg, type);

    //标志默认值  默认值是阻塞类型 
    ret = msgsnd(msgid, &msg, sizeof(msg), 0);
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









