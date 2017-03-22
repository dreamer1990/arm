#include <stdio.h>

/*
 *6. 文件的读写
 *    在顺序写时，先写入的数据存放在文件中前面，后写入的数据存放在文件中后面
 *    在顺序读时，先读文件中前面的数据，后读文件中后面的数据
 *    对顺序读写来说，对文件读写数据的顺序和数据在文件中的物理顺序是一致的 
 *    顺序读写需要用库函数实现
 */

/*
 *    int fgetc(FILE *stream);
 *    功能:从流中获取一个字符
 *    参数:
 *        stream: 文件流指针
 *    返回值:
 *        成功: 返回获取的字符
 *        失败: 返回EOF
 */
int main(void)
{
    FILE *fp = NULL;

    int ch = 0;

    //1. 打开文件
    fp = fopen("txt", "r");
    if (NULL == fp)
    {
        printf("fopen failed...\n"); 
        goto err0;
    }

    //2. 读文件
    //ch = fgetc(fp);
    //printf("ch = %c\n", ch);
    while(1)
    {
        ch = fgetc(fp); 
        //读到文件结尾
        if (-1 == ch)
            break;
        printf("%c", ch); 
    }
    //putchar('\n');

    //3. 关闭文件
    fclose(fp);

    return 0;
err0:
    return -1;
}






