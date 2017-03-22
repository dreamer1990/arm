#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <linux/pagemap.h>

#include <plat/map-base.h>
#include <plat/map-s5p.h>

#define DEV_NAME    "test-dev"

int test_init(void)
{
    printk("test init\n");
    printk("CHIP_ID: %p (%x)\n", S5P_VA_CHIPID, *(volatile unsigned int *)(S5P_VA_CHIPID));
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



