#include <stdio.h>
#include <string.h>

//声明一个结构体类型
struct per_t {
    char name[32];  //姓名
    int count;      //票数
};

//显示结构体数组中的信息
void per_show(struct per_t per[], int n)
{
    int i = 0;

    //逐个输出结构体数组中的元素
    for (i = 0; i < n; i++)
    {
        printf("name:  %s -----> %d\n", per[i].name, per[i].count); 
    }
}


int main(int argc, char **argv)
{
    char name[32];
    //定义一个结构体数组 并且初始化
    struct per_t per[3] = {{"zhang", 0} , {"li", 0}, {"wang", 0}};
    int i = 0;

    per_show(per, 3);

    while(1)
    {
        printf("please input a name[zhang/li/wang]: "); 
        //gets(name);
        fgets(name, 32, stdin);
        //name[strlen(name) - 1] = '\0';

        if (strncmp(name, "exit", 4) == 0)
        {
            printf("投票结束....\n");
            break; 
        }

        for (i = 0; i < 3; i++)
        {
            //判断被投票的人的姓名
            if (strncmp(name, per[i].name, strlen(per[i].name)) == 0) 
            {
                //票数加1
                per[i].count ++; 
                //退出当层循环 for循环
                break;
            }
        }
    }

    //显示投票结果
    per_show(per, 3);

    return 0;
}
