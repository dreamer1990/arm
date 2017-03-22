#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>

#define DEV_NAME    "test-dev"

struct completion com;
struct semaphore sem;
ssize_t test_read (struct file *filp, char __user *buf, size_t size, loff_t *offset)
{
    printk("test read\n");
    
    //wait_for_completion(&com);
    if(IS_ERR_VALUE(down_interruptible(&sem)))
        return -ERESTARTSYS;

    return size;
}

ssize_t test_write (struct file *filp, const char __user *buf, size_t size, loff_t *offset)
{
    printk("test write\n");

    //complete(&com);
    up(&sem);

    return size;
}

int test_open(struct inode *inode, struct file *filp)
{
    printk("test open\n");
    return 0;
}

int test_close (struct inode *inode, struct file *filp)
{
    printk("test close\n");
    return 0;
}

struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = test_open, 
    .release = test_close,
    .read = test_read,
    .write = test_write,
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

    //spin_lock_init(&slock);
    //atomic_set(&value, 0);
    //init_completion(&com);
    sema_init(&sem, 0);

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



