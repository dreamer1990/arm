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
#include <linux/io.h>
#include <linux/device.h>

#define DRV_NAME    "test-dev1"

extern struct bus_type mini;

int test_probe (struct device *dev)
{
    printk("test drv1 probe\n");
    return 0;
}

int test_remove (struct device *dev)
{
    printk("test drv1 remove\n");
    return 0;
}

struct device_driver drv = {
    .name = DRV_NAME,
    .bus = &mini,
    .owner = THIS_MODULE,
    .probe = test_probe,
    .remove = test_remove,
};

int test_init(void)
{
    int ret;
    printk("test init\n");
    ret = driver_register(&drv);
    if(IS_ERR_VALUE(ret))
    {
        return ret;
    }
    return 0;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    driver_unregister(&drv);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



