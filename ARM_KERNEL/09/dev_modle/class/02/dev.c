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

#define DEV_NAME    "test-dev"

extern struct class cla;

void test_release(struct device *dev)
{
    printk("test release\n");
}

struct device dev = {
    .init_name = DEV_NAME,
    .class = &cla, 
    .release = test_release,
};

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

int major = 0;
struct file_operations fops = {
    .owner = THIS_MODULE, 
    .open = test_open,
    .release = test_close,
};
int test_init(void)
{
    int ret;
    printk("test init\n");
    
    ret = register_chrdev(major, DEV_NAME, &fops);
    if(IS_ERR_VALUE(ret))
    {
        return ret;
    }
    if(0 == major)
    {
        major = ret;
    }
    printk("major: %d\n", major);

    dev.devt = MKDEV(major, 0);
    ret = device_register(&dev);
    if(IS_ERR_VALUE(ret))
    {
        unregister_chrdev(major, DEV_NAME);
        return ret;
    }
    return 0;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    device_unregister(&dev);
    unregister_chrdev(major, DEV_NAME);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



