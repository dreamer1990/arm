#include <stdio.h>


//int printf(const char *format, ...);

/*
 *    int fprintf(FILE *stream, const char *format, ...);
 *    功能: 类似于printf,但是输出由stream指定
 *    参数:
 *        stream: 文件指针
 *        format: 输出格式
 *        ...: 变参
 *    返回值:
 *        正确输出字符的个数 
 *
 */
//int sprintf(char *str, const char *format, ...);

//int snprintf(char *str, size_t size, const char *format, ...);

/*
 *       int fscanf(FILE *stream, const char *format, ...);
 *       功能:类似于scanf,但是输入流由stream指定
 *       参数:
 *            stream: 文件指针
 *            format: 输出格式
 *            ...: 变参
 *        返回值:
 *            正确输出字符的个数 
 *
 */


int main(void)
{
    FILE *fp = NULL;
    char buf[32] = "hello uplooking";

    int a, b, c;

    fp = fopen("txt", "w+"); 
    if (NULL == fp)
    {
        printf("fopen file error...\n"); 
        goto err0;
    }
    //与printf("====> %s\n", buf);等价
    fprintf(stdout, "====> %s\n", buf);

        fprintf(fp, "%d %d %d %s\n", 1, 2, 3, buf);
    //将文件指针指向文件开始的地方
    rewind(fp);
    //从文件中一次读取数据,分贝保存到a, b, c, buf中
    fscanf(fp, "%d %d %d %s", &a, &b, &c, buf);

    printf("a = %d b = %d c = %d buf = %s\n", a, b, c, buf);
    //将字符串buf向文件流fp中输出
    fprintf(fp, "===> %s\n", buf);

    //等价于scanf("%d %d %d", &a, &b, &c)
    fscanf(stdin, "%d  %d  %d", &a, &b, &c);
    printf("a = %d  b = %d c = %d\n", a, b, c);


    fclose(fp);
    return 0;
err0:
    return -1;
}







