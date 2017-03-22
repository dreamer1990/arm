#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>

#define DEV_NAME    "test-dev"

int lock = 0;

void func(void)
{
    int value;
    int ret;
    asm __volatile__(
        "ldrex %0, [%1]\n\t"
        : "=r" (value)
        : "r" (&lock)
        : "memory"
    );

    printk("value = %d\n", value);

    asm __volatile__(
        //"mov r0, #10\n\t"
        //"strex %0, r0, [%2]\n\t"
        "ldrex r0, [%2]\n\t"
        //"cmp r0, #0\n\t"
        "strex %0, %1, [%2]\n\t"
        : "=&r" (ret)
        : "r" (1), "r" (&lock)
        : "memory", "r0"
    );

    printk("ret: %d lock: %d\n", ret, lock);

}


int test_open(struct inode *inode, struct file *filp)
{
    printk("test open\n");
    
    func();

    return 0;
}

int test_close (struct inode *inode, struct file *filp)
{
    printk("test close\n");
    return 0;
}

struct file_operations fops = {
    .open = test_open, 
    .release = test_close,
};

int major = 0;
dev_t devno;
struct cdev *cdev;
int test_init(void)
{
    int ret;
    printk("test init\n");
    if(major == 0)
    {
        ret = alloc_chrdev_region(&devno, 0, 4, DEV_NAME);
        if(ret < 0)
        {
            return ret;
        }

        major = MAJOR(devno);
    }
    else
    {
        ret = register_chrdev_region(MKDEV(major, 0), 4, DEV_NAME);
        if(ret < 0)
        {
            return ret;
        }
    }
    printk("major: %d\n", major);

    cdev = cdev_alloc();   
    if(NULL == cdev)
    {
        unregister_chrdev_region(MKDEV(major, 0), 4);
        return -ENOMEM;
    }

    cdev_init(cdev, &fops);
    cdev->owner = THIS_MODULE;

    ret = cdev_add(cdev, MKDEV(major, 0), 4);
    if(ret < 0)
    {
        unregister_chrdev_region(MKDEV(major, 0), 4);
        return ret;
    }

    return 0;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    cdev_del(cdev);
    unregister_chrdev_region(MKDEV(major, 0), 4);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



