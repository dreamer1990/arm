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

#include <linux/platform_device.h>

#define DRV_NAME    "test-aaa"

struct mini_test_info {
    int w;
    int h;
    int ch;
};

int test_probe (struct platform_device *dev)
{
    int i;
    struct resource *res = dev->resource;
    struct mini_test_info *info = dev->dev.platform_data;
    printk("test drv probe: devname: %s\n", dev->name);

    for(i = 0; i < dev->num_resources; i++)
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

int test_remove (struct platform_device *dev)
{
    printk("test drv remove: devname: %s\n", dev->name);
    return 0;
}

struct platform_device_id id_table[] = {
    {"test-dev0", 0},
    {"test-adc", 1},
    {"test-abc", 2},
    {}
};

struct platform_driver drv = {
    .driver = {
        .name = DRV_NAME,
        .owner = THIS_MODULE,
    },
    .probe = test_probe,
    .remove = test_remove,
    .id_table = id_table,
};

int test_init(void)
{
    int ret;
    printk("test init\n");
    ret = platform_driver_register(&drv);
    if(IS_ERR_VALUE(ret))
    {
        return ret;
    }
    return 0;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    platform_driver_unregister(&drv);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



