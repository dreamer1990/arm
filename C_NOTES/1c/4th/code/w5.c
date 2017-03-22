#include <stdio.h>
#include <string.h>

//返回字符串长度
size_t my_strlen(const char a[])
{
    int i = 0;

    //字符串是以\0结尾
    while('\0' != a[i++])
        ;

    return i - 1;
}

//字符串拷贝函数
void my_strcpy(char dst[], char src[])
{
    int i = 0;
/*
 *    if (strlen(dst) < strlen(src))
 *    {
 *        printf("error : the length of dst is shorter than src\n");
 *        goto err0;
 *    }
 */

    while('\0' != (dst[i++] = src[i]))
        ;
}

//拷贝n个字符到dst数组中
void my_strncpy(char dst[], char src[], int n)
{
    int i = 0;

    while(i < n && ('\0' != (dst[i++] = src[i])))
        ;

    dst[i] = '\0';
}

//字符串连接函数
void my_strcat(char dst[], char src[])
{
    int i = 0;
    int j = 0;

    while('\0' != dst[i++])
        ;
    i--;
    while('\0' != (dst[i++] = src[j++]))
        /*do nothing*/;
}

//指定连接n个字符
void my_strncat(char dst[], char src[], int n)
{
    int i = 0;
    int j = 0;

    while('\0' != dst[i++])
        ;
    i--;

    while(j < n && '\0' != (dst[i++] = src[j++]))
        ;
    dst[i] = '\0';
}

//字符串比较函数
int my_strcmp(const char dst[], const char src[])
{
    int i = 0;
    int j = 0;

    while(dst[i] == src[j] && '\0' != dst[i])
        i++, j++;
   
    if (dst[i] > src[j])
        return 1;
    else if (dst[i] < src[j])
        return -1;
    else
        return 0;
}

//在src字符串中找到字符c的索引
int my_strchr(const char src[], int c) 
{
    int i = 0;

    while(0 != src[i])
    {
        if (src[i] == c) 
            break;
        i++;
    }

    // 0  '\0'等价
    if (0 == src[i])
        goto err0;

    return i;
err0:
    return -1;
}

int main(void)
{
    char str[] = "hello world\0aaaaaa";
    char dst[64];

    printf("len:  %d  %d\n", strlen(str), my_strlen(str));

    printf("==============test strcpy====================\n");
    my_strcpy(dst, str);
    printf("dst:  %s\n", dst);

    printf("============test strncpy===================\n");
    //将数组中所有的元素都设置为0
    memset(dst, 0, sizeof(dst));
    my_strncpy(dst, "hello", 6);
    printf("dst:  %s\n", dst);

    printf("============test strcat=================\n");
    my_strcat(dst, "AAA");
    printf("dst:  %s\n", dst);

    printf("==================test strncat=================\n");
    my_strncat(dst, "ABCDEFGHI", 3);
    printf("dst: %s\n", dst);

    printf("=============test strcmp=========================\n");
    printf("%d\n", my_strcmp("ABCDE", "ABCD"));

    printf("=============test strchr==================\n");
    printf("index:  %d\n", my_strchr("ABCDEF", 'E'));
    printf("index:  %d\n", my_strchr("ABCDEF", 'G'));

    return 0;
}
