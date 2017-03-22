#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>


int main(void)
{
    DIR* dir = NULL;
    struct dirent *dir_entry = NULL;

    //打开一个目录
    dir = opendir("test1");
    if (NULL == dir)
    {
        perror("opendir"); 
        goto  err0;
    }

    //man 3 readdir
    //读取目录中的内容 
    while((dir_entry = readdir(dir)) != NULL)
    {
        printf("%s\n", dir_entry->d_name);
    }

    
    //关闭已经打开的目录
    closedir(dir);
     

    return 0;
err0:
    return -1;
}
