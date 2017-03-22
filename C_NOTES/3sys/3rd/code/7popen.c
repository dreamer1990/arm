#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 32

int main(int argc, char **argv)
{
    FILE *fin = NULL, *fout = NULL;
    char buf[SIZE];
    int ret = 0;
 
    fout = popen(argv[1], "w");
    if (NULL == fout)
    {
        perror("popen"); 
        goto err1;
    }
   
    fin = popen(argv[2], "r");
    if (NULL == fin)
    {
        perror("popen"); 
        goto err0;
    }

    while(NULL != fgets(buf, SIZE, fin)) 
    {
        ret = fputs(buf, fout);  
        if (ret < 0)
        {
            perror("fputs");
            break;
        } 
    }


    //关闭
    pclose(fin);
    pclose(fout);

    return 0;
err1:
    pclose(fin);
err0:
    return -1;
}
