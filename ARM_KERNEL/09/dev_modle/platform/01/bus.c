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

#define BUS_NAME    "test-bus"

int mini_match(struct device *dev, struct device_driver *drv)
{
    printk("devname: %s drvname: %s\n", dev->kobj.name, drv->name);

    return !strcmp(dev->kobj.name, drv->name);
    //return 0;   //不匹配(0) 匹配(非0)
}

struct bus_type mini = {
    .name = BUS_NAME,
    .match = mini_match,
};
EXPORT_SYMBOL(mini);

int test_init(void)
{
    int ret;
    printk("test init\n");
    ret = bus_register(&mini);
    if(IS_ERR_VALUE(ret))
    {
        return ret;
    }
    return 0;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    bus_unregister(&mini);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



