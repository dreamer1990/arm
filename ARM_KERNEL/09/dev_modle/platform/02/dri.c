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

#include "mini_device.h"

#define DRV_NAME    "test-dev0"

int test_probe (struct mini_device *dev)
{
    int i;
    struct resource *res = dev->resources;
    struct mini_test_info *info = dev->dev.platform_data;
    printk("test drv probe: devname: %s\n", dev->name);

    for(i = 0; i < dev->resource_num; i++)
    {
        if(res[i].flags == IORESOURCE_IO)
        {
            printk("gpio_set_value: s3c_gpio_set_config: %d ~ %d\n",
                    res[i].start, res[i].end);
        }
        if(res[i].flags == IORESOURCE_IRQ)
        {
            printk("request_irq: irq_handler: %d ~ %d\n",
                    res[i].start, res[i].end);
        }
        if(res[i].flags == IORESOURCE_MEM)
        {
            printk("iowrite32 ioread32 : %d ~ %d\n",
                    res[i].start, res[i].end);
        }
    }

    printk("info: w[%d] h[%d] ch[%d]\n", info->w, info->h, info->ch);
    
    return 0;
}

int test_remove (struct mini_device *dev)
{
    printk("test drv remove: devname: %s\n", dev->name);
    return 0;
}

struct mini_driver drv = {
    .name = DRV_NAME,
    .owner = THIS_MODULE,
    .probe = test_probe,
    .remove = test_remove,
};

int test_init(void)
{
    int ret;
    printk("test init\n");
    ret = mini_driver_register(&drv);
    if(IS_ERR_VALUE(ret))
    {
        return ret;
    }
    return 0;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    mini_driver_unregister(&drv);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



