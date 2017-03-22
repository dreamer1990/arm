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
#include <linux/miscdevice.h>

#include <linux/platform_device.h>

#define DRV_NAME    "test-led"

void *reg_base;
int reg_size;

void led_set(int cmd, int arg)
{
    if(cmd)
    {
        iowrite32(ioread32(reg_base + 4) &~ (1<<arg), reg_base + 4);
    }
    else
    {
        iowrite32(ioread32(reg_base + 4) | (1<<arg), reg_base + 4);
    }
}

void led_allon(void)
{
    iowrite32(ioread32(reg_base + 4) &~ 0xf, reg_base + 4);   
}

void led_alloff(void)
{
    iowrite32(ioread32(reg_base + 4) | 0xf, reg_base + 4);   
}

void led_init(void)
{
    iowrite32(ioread32(reg_base) &~ 0xffff, reg_base);
    iowrite32(ioread32(reg_base) | 0x1111, reg_base);

    led_alloff();
}

long test_ioctl (struct file *filp, unsigned int cmd, unsigned long arg)
{
    switch(cmd)
    {
        case 0:
        case 1:
            led_set(cmd, arg);
            break;
        default:
            return -EINVAL;
    }
    return 0;
}


struct file_operations fops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = test_ioctl,
};

struct miscdevice mdev = {
    .name = DRV_NAME,
    .minor = MISC_DYNAMIC_MINOR,
    .fops = &fops,
};

int test_probe (struct platform_device *dev)
{
    int ret;
    struct resource *res;
    printk("test drv probe: devname: %s\n", dev->name);
    
    res = platform_get_resource(dev, IORESOURCE_MEM, 0); 
    if(IS_ERR_OR_NULL(res))
    {
        ret = -ENOMEM;
        goto ERROR_get_resource_mem;
    }
    
    reg_size = resource_size(res);
    reg_base = ioremap(res->start, reg_size);
    if(IS_ERR_OR_NULL(reg_base))
    {
        ret = -ENOMEM;
        goto ERROR_ioremap;
    }

    led_init();

    ret = misc_register(&mdev);
    if(IS_ERR_VALUE(ret))
    {
        goto ERROR_misc_register;
    }
    
    return 0;
ERROR_misc_register:
    iounmap(reg_base);
ERROR_ioremap:
ERROR_get_resource_mem:
    return ret;
}

int test_remove (struct platform_device *dev)
{
    printk("test drv remove: devname: %s\n", dev->name);
    iounmap(reg_base);
    misc_deregister(&mdev);
    return 0;
}

struct platform_device_id id_table[] = {
    {"test-dev0", 0},
    {"test-adc", 1},
    {"test-abc", 2},
    {"test-led", 3},
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
    printk("test init\n");
    return platform_driver_register(&drv);
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



