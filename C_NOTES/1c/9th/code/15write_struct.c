#include <stdio.h>
#include <string.h>


typedef struct _stu_t {
    int id;
    char sex;
    char name[32];
}stu_t;

int main(void)
{
    FILE *fp = NULL;
    int ret = 0;
    int i = 0;

    //结构体数组的初始化
    stu_t stu[3] = {
    {
        .id = 3,
        .sex = 'M',
        .name = "uplooking",
    },
    {
        .id = 4,
        .sex = 'F',
        .name = "AAAAAA",
    },
    {
        .id = 5,
        .sex = 'M', 
        .name = "bbbbb",
    }
    };

    //以读写的方式打开一个文件,如果文件不存在,就创建该文件
    fp = fopen("person.db", "w+");
    if (NULL == fp)
    {
        printf("fopen file error...\n");
        goto err0;
    }

    //将结构体数组中的元素批量写入文件
    ret = fwrite(stu, sizeof(stu_t), 3, fp);
    printf("ret = %d\n", ret);
    
    memset(stu, 0, 3 * sizeof(stu_t));
    //将文件指针指向文件的开头
    rewind(fp);

    ret = fread(stu, sizeof(stu_t), 3, fp);
    for (i = 0; i < 3; i++)
    {
    
        printf("id: %d sex: %c name: %s\n", stu[i].id, stu[i].sex, stu[i].name); 
    }

    //关闭文件
    fclose(fp);
    return 0;
err0:
    return -1;
}
