#include <stdio.h>

#define SIZE 128

#define my_scanf(err_op, format, ...)   do{     \
        int ret = 0;                            \
        ret = scanf(format, __VA_ARGS__);       \
        while('\n' != getchar())                \
            /*do nothing*/;                     \
        if (ret <= 0)                           \
            err_op;                             \
}while(0)

#define my_gets(err_op, buf) do{                \
        char *p = NULL;                         \
        p = fgets(buf, SIZE, stdin);            \
        while('\n' != getchar())                \
            /*do nothing*/;                     \
        if (NULL == p)                          \
            err_op;                             \
}while(0)

int main(void)
{
    int a = 0;

    char buf[SIZE];

    while(1)
    {
    retry:
        printf("please input a number:  "); 
        //scanf("%d", &a);
        my_scanf(goto retry, "%d", &a);
        if(-1 == a)
            break;

        printf("----> %d\n", a);
    }

    my_gets(,buf);
    puts(buf);

    return 0;
}
