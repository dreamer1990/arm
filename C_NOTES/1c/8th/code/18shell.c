#include <stdio.h>

struct cmd_t {
    char cmd[32];
    int a;
    int b;
    char help[32];
};

//显示帮助信息的函数
void show_help(struct cmd_t *p, int n)
{
    int i = 0;
    for (i = 0; i < n; i++, p++)
    {
        printf("%s\n", p->help); 
    }
}


int main(void)
{
    char buf[32];
    //结构体数组
    struct cmd_t command[] = {
    {.cmd = "add", .help = "两个数相加 add(a, b)"},
    {.cmd = "sub", .help = "两个数相减 sub(a, b)"},
    {.cmd = "mul", .help = "两个数相乘 mul(a, b)"},
    {.cmd = "div", .help = "两个数相除 div(a, b)"},
    }; 

    //show_help(command, sizeof(command) / sizeof(command[0]));
    while(1)
    {
        fgets(buf, 32, stdin);    
        if (strncmp(buf, "exit", 4) == 0)
        {
            printf("期待下次光临.....\n"); 
            break;
        }
        if (strncmp(buf, "help", 4) == 0)
        {
            show_help(command, sizeof(command) / sizeof(command[0]));
        }
    }

    return 0;
}
