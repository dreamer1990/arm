#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[128];
    int count = 0;
    int flag = 0;
    int i = 0;

    printf("please input a string....\n");

    gets(str);
    puts(str);

    //统计有多少个单词
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')         
        {
            flag = 1; 
        }

        if (1 == flag && str[i] == ' ')
        {
            flag = 0;
            count++;
        }
    }

    if (' ' != str[i - 1])
    {
        count++; 
    }

    printf("count:  %d\n", count);

    return 0;
}
