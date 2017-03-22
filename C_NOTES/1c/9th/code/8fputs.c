#include <stdio.h>

    /*
     *int fputs(const char *s, FILE *stream);
     *功能: 将字符串写入到文件中,但是不将'\0'写入到文件中
     *参数:
     *    s: 字符串指针
     *    stream: 文件指针
     *返回值:
     *    成功: 非负值
     *    失败: EOF
     *    
     */

int main(void)
{
    FILE *fp = NULL;
    char buf[32];
    //以只写的方式打开文件
    fp = fopen("txt", "w");
    if (NULL == fp)
    {
        printf("fopen file failed..\n");  
        goto err0;
    }

    while(1)
    {
        //从标准输入获取字符串
        fgets(buf, 32, stdin);  
        //如果是exit就退出循环
        if (strncmp(buf, "exit", 4) == 0)
            break;
        //将获取的字符串写入到文件流中
        fputs(buf, fp); 
    }

    //关闭文件
    fclose(fp);
    return 0;
err0:
    return -1;
}
