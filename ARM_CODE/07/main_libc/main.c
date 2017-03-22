#include <config.h>
#include <string.h>

//int array[1024];    //.bss
//int brray[1024] = {1,2,3,4};    //.data
int sum = 0;            //.bss
int array[1024] = {};   //.bss

/*
extern void __bss_start();  
extern void __bss_end();
*/

extern unsigned int __bss_start;
extern unsigned int __bss_end;

int main(void)
{
/*
    memset(__bss_start, 0, __bss_end - __bss_start);    //清空整个bss段;
*/
    memset(&__bss_start, 0, (u32)&__bss_end - (u32)&__bss_start);

/*
    memset(array, 0, 1024 * 4);
    sum = 0;
*/
    printf("hello world\n");
    int i;
    for(i = 0; i < 1024; i++)
        printf("array[%d] = %d\n", i, array[i]);
    printf("sum = %d\n", sum);

    return 0;
}
