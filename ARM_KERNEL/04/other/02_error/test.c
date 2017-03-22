#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>

#define DEV_NAME    "test-dev"

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
        if(IS_ERR_VALUE(ret))
        {
            goto ERROR_alloc_chrdev;
        }

        major = MAJOR(devno);
    }
    else
    {
        ret = register_chrdev_region(MKDEV(major, 0), 4, DEV_NAME);
        if(IS_ERR_VALUE(ret))
        {
            goto ERROR_alloc_chrdev;
        }
    }
    printk("major: %d\n", major);

    cdev = cdev_alloc();   
    if(IS_ERR_OR_NULL(cdev))
    {
        ret = -ENOMEM;
        goto ERROR_cdev_alloc;
    }

    cdev_init(cdev, &fops);
    cdev->owner = THIS_MODULE;

    ret = cdev_add(cdev, MKDEV(major, 0), 4);
    if(IS_ERR_VALUE(ret))
    {
        goto ERROR_cdev_add;
    }

    return 0;
ERROR_cdev_add:
    kfree(cdev);
ERROR_cdev_alloc:
    unregister_chrdev_region(MKDEV(major, 0), 4);
ERROR_alloc_chrdev:
    return ret;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    //unregister_chrdev(major, DEV_NAME);
    cdev_del(cdev);
    unregister_chrdev_region(MKDEV(major, 0), 4);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



