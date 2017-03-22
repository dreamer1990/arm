#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char ** argv, char **env)
{
    FILE *fp;
    fp = fopen("/dev/console", "r+");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }

    //fwrite("hello user\n", 1, 11, fp);
    int i = 0;
    while(env[i])
    {
        fprintf(fp, "env[%d]: %s\n", i, env[i]);
        i++;
    }


    fclose(fp);
    return 0;
}
