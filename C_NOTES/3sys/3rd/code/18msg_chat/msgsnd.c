
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

void show_msg(void *data)
{
    struct msgbuf* p = data;
    //输出消息类型
    printf("msg type: %ld\n", p->mtype);
    //输出消息正文
    printf("id: %d sex: %c name: %s\n", p->stu.id, p->stu.sex, p->stu.name);
}

void create_msg(void *data, int type)
{
    struct msgbuf* p = data;

    p->mtype = type;
    p->stu.id = random() % 100;
    p->stu.sex = "MF"[random() % 2];
    strcpy(p->stu.name, "uplooking");
}

int main(void)
{
    int ret = -1;
    int msgid = -1;
    int i = 0;
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

    for (i = 0; i < 5; i++)
    {

        //tom
        memset(&msg, 0, sizeof(msg));
        create_msg(&msg, 1);
        //标志默认值  默认值是阻塞类型 
        ret = msgsnd(msgid, &msg, sizeof(stu_t), 0);
        if (ret < 0)
        {
            perror("msgsnd");    
            goto err0;
        }

        //tim
        memset(&msg, 0, sizeof(msg));
        create_msg(&msg, 2);
        //标志默认值  默认值是阻塞类型 
        ret = msgsnd(msgid, &msg, sizeof(stu_t), 0);
        if (ret < 0)
        {
            perror("msgsnd");    
            goto err0;
        }

        //lucy
        memset(&msg, 0, sizeof(msg));
        create_msg(&msg, 3);
        //标志默认值  默认值是阻塞类型 
        ret = msgsnd(msgid, &msg, sizeof(stu_t), 0);
        if (ret < 0)
        {
            perror("msgsnd");    
            goto err0;
        }
        system("ipcs -q");

        sleep(1);
    }

    return 0;
err0:
    return -1;
}









