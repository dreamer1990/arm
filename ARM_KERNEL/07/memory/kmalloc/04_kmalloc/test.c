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
    int *p;
    printk("test init\n");
    p = kmalloc(4 * 1024 * 1024/* + 1*/, GFP_KERNEL);  //开辟空间, 没有足够空间阻塞等待;
    if(IS_ERR_OR_NULL(p))
    {
        return -ENOMEM;
    }
    printk("p : %p\n", p);
    kfree(p);

    printk("MAX_SIZE: %ld\n", KMALLOC_MAX_SIZE);

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



