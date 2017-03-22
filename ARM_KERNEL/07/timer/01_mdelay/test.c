#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>
#include <linux/interrupt.h>
#include <linux/slab.h>

#define DEV_NAME    "test-dev"

void __mdelay(unsigned long ms)
{
    unsigned long end = jiffies + msecs_to_jiffies(ms);
    while(time_is_after_jiffies(end))
        ;
}

int test_init(void)
{
    unsigned int val;
    printk("test init\n");
    printk("jiffies: %lu\n", jiffies);
    val = jiffies;
    __mdelay(1239);
    printk("jiffies: %lu val: %lu\n", jiffies, jiffies - val);
    val = jiffies;
    mdelay(1239);
    printk("jiffies: %lu val: %lu\n", jiffies, jiffies - val);

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



