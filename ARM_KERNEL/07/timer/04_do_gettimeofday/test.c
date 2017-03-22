#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>
#include <linux/interrupt.h>
#include <linux/slab.h>

#define DEV_NAME    "test-dev"

int test_init(void)
{
    struct timeval tval;
    struct tm tm;
    printk("test init\n");
    do_gettimeofday(&tval);
    printk("tval.tv_sec: %lu tval.tv_usec: %lu\n", tval.tv_sec, tval.tv_usec);
    time_to_tm(tval.tv_sec, 0, &tm);
    printk("%ld-%d-%d %d:%d:%d\n", 
                    1900 + tm.tm_year, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    return 0;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



