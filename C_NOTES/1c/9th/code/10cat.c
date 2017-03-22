#include <stdio.h>
#include <string.h>

#define SIZE 32

/*
 *stdin   //标准输入
 *stdout  //标准输出
 *stderr  //标准出错
 */

//实现cat简单的命令
int main(int argc, char **argv)
{
    char buf[SIZE];
    char *p;
    FILE *fp = NULL;

    if (argc < 2)
    {
        while(1)  
        {
            p = fgets(buf, SIZE, stdin); 
            if (NULL == p)
                break;
            if (strncmp(buf, "exit", 4) == 0)
                break;

            fputs(buf, stdout);
        }
    }
    else
    {
        //cat filename 
        fp = fopen(argv[1], "r");
        if (NULL == fp)
        {
            printf("fopen file error....\n");
            goto err0;
        }

        //while(!feof(fp))
        while(1)
        {
            //从文件流中获取字符串
            p = fgets(buf, SIZE, fp); 
            if (NULL == p)
                break;
            //将buf中向标准输出输出
            fputs(buf, stdout);
        }
        //关闭文件    
        fclose(fp);
    }

    return 0;
err0:
    return -1;
}
