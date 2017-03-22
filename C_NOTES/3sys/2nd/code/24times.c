#include <stdio.h>
#include <sys/times.h>


#if 0
clock_t times(struct tms *buf);

struct tms {
    clock_t tms_utime;  /* user time */
    clock_t tms_stime;  /* system time */
    clock_t tms_cutime; /* user time of children */
    clock_t tms_cstime; /* system time of children */
};

#endif

int main(void) 
{
    struct tms buf;

    sleep(1);

    //获取进程的时间
    if (times(&buf) < 0)
        perror("times");

    printf("utime: %ld\n", buf.tms_utime);
    printf("stime: %ld\n", buf.tms_stime);
    printf("cutime: %ld\n", buf.tms_cutime);
    printf("cstime: %ld\n", buf.tms_cstime);


    return 0;
}
