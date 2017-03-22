#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[3][64];
    char tmp[64];
    int i = 0;

    printf("please input three strings.\n");

    for (i = 0; i < 3; i++)
    {
        gets(str[i]); 
    }

    //先判断str[0] 和str[1]
    if (strcmp(str[0], str[1]) > 0)
    {
        strcpy(tmp, str[0]); 
        strcpy(str[0], str[1]);
        strcpy(str[1], tmp);
    }

    //判断str[0] str[2]
    if (strcmp(str[0], str[2]) > 0)
    {
        strcpy(tmp, str[0]); 
        strcpy(str[0], str[2]);
        strcpy(str[2], tmp);
    }

    //判断str[1], str[2]
    if (strcmp(str[1], str[2]) > 0)
    {
        strcpy(tmp, str[1]); 
        strcpy(str[1], str[2]);
        strcpy(str[2], tmp);
    }
    
    printf("==================\n");
    for (i = 0; i < 3; i++)
    {
        printf("%s\n", str[i]);
    }
    return 0;
}
