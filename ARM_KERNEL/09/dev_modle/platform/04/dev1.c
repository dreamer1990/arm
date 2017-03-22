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
#include <linux/gpio.h>

#include <linux/platform_device.h>

#define DEV_NAME    "test-adc"

struct resource res[] = {
    {
        .start = EXYNOS4X12_GPM4(0),
        .end = EXYNOS4X12_GPM4(3),
        .flags = IORESOURCE_MEM,
    },
    {
        .start = IRQ_EINT(26),
        .end = IRQ_EINT(29),
        .flags = IORESOURCE_IRQ,
    },
    {
        .start = 0x40000000,
        .end = 0x80000000,
        .flags = IORESOURCE_MEM,
    }
};

struct mini_test_info{
    int w;
    int h;
    int ch;
};

struct mini_test_info info = {
    .w = 480,
    .h = 800,
    .ch = 0,
};

void test_release(struct device *dev)
{
    printk("test release\n");
}

struct platform_device dev = {
    .name = DEV_NAME,
    .id = -1,
    .resource = res,
    .num_resources = ARRAY_SIZE(res),
    .dev.platform_data = &info,
    .dev.release = test_release,
};

int test_init(void)
{
    int ret;
    printk("test init\n");
    ret = platform_device_register(&dev);
    if(IS_ERR_VALUE(ret))
    {
        return ret;
    }
    return 0;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    platform_device_unregister(&dev);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



