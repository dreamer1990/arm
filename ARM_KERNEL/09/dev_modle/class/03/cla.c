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
#include "mini_cla_device.h"

#define DEV_NAME    "mini-dev"

extern struct class mini_cla;
int g_minor = 0;

void mini_g_release(struct device *dev)
{
}

int test_open (struct inode *inode, struct file *filp)
{
    printk("test open\n");
    return 0;
}

int test_close (struct inode *inode, struct file *filp)
{
    printk("test close\n");
    return 0;
}

int major = 250;
struct file_operations fops = {
    .owner = THIS_MODULE, 
    .open = test_open,
    .release = test_close,
};

int mini_class_device_register(struct mini_cla_device *cla_dev)
{
    int ret;
    char *name;
    struct device *dev;
    printk("%s register\n", cla_dev->name);
    dev = &cla_dev->dev;
    dev->class = &mini_cla;
    dev->release = mini_g_release;

    ret = register_chrdev(major, DEV_NAME, &fops);
    if(IS_ERR_VALUE(ret))
    {
        return ret;
    }
    if(0 == major)
    {
        major = ret;
    }
    dev->devt = MKDEV(major, g_minor);
    name = kzalloc(100, GFP_KERNEL);
    if(IS_ERR_OR_NULL(name))
    {
        unregister_chrdev(major, DEV_NAME);
        return -ENOMEM;
    }
    sprintf(name, "%s%d", DEV_NAME, g_minor++);
    dev->init_name = name;

    ret = device_register(dev);
    if(IS_ERR_VALUE(ret))
    {
        kfree(name);
        unregister_chrdev(major, DEV_NAME);
        return ret;
    }

    kfree(name);
    return 0;
}
EXPORT_SYMBOL(mini_class_device_register);

void mini_class_device_unregister(struct mini_cla_device *cla_dev)
{
    device_unregister(&cla_dev->dev);   
    unregister_chrdev(major, DEV_NAME);
}
EXPORT_SYMBOL(mini_class_device_unregister);


MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



