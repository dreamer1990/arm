#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main(void)
{
    key_t key = -1;

    //创建一个key
    key = ftok("a.out", 6);
    if (key < 0)
    {
        perror("ftok"); 
        goto err0;
    }

    printf("key = %d\n", key);
    printf("=======================\n");

    //如果name 和 id相同 则创建的key一样
    //创建一个key
    key = ftok("a.out", 6);
    if (key < 0)
    {
        perror("ftok"); 
        goto err0;
    }

    printf("key = %d\n", key);
    printf("=======================\n");
    

    //IPC_PRIVATE --> 0
    //创建一个key
    key = ftok("a.out", IPC_PRIVATE);
    if (key < 0)
    {
        perror("ftok"); 
        goto err0;
    }

    printf("key = %d\n", key);
    printf("=======================\n");

    //创建一个key
    key = ftok("a.out", IPC_PRIVATE);
    if (key < 0)
    {
        perror("ftok"); 
        goto err0;
    }

    printf("key = %d\n", key);
    printf("=======================\n");






    return 0;
err0:
    return -1;
}
