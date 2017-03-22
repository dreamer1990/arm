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

#define DEV_NAME    "test-dev"

int test_init(void)
{
    printk("test init\n");
    printk("VMALLOC_END  : %lx\n", VMALLOC_END);
    printk("VMALLOC_START: %lx\n", VMALLOC_START);
    printk("high_memory  : %p\n", high_memory);
    printk("PAGE_OFFSET  : %lx\n", PAGE_OFFSET);
    printk("MODULES_END  : %lx\n", MODULES_END);
    printk("MODULES_VADDR: %lx\n", MODULES_VADDR);
    printk("TASK_SIZE    : %lx\n", TASK_SIZE);

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



