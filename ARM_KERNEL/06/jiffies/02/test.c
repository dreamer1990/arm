#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>
#include <linux/interrupt.h>
#include <linux/slab.h>

#define DEV_NAME    "test-dev"

void __delay(int s)
{
    unsigned long start = jiffies;          //0xffffffff    -1
    unsigned long end = start + s * HZ;     //599           599

    //while(jiffies < end)
    //    ;

    while(time_is_after_jiffies(end))
        ;
}   

int test_init(void)
{
    printk("test init\n");
    printk("jiffies: %lu\n", jiffies);
    __delay(3);
    printk("jiffies: %lu\n", jiffies);

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



