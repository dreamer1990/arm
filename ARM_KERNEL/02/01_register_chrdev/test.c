#include <linux/module.h>
#include <linux/fs.h>

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
int test_init(void)
{
    int ret;
    printk("test init\n");
    ret = register_chrdev(major, DEV_NAME, &fops);
    if(ret < 0)
    {
        return ret;
    }
    if(major == 0)      //动态申请到主设备号;
    {
        major = ret;
    }
    printk("major : %d\n", major);

    return 0;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    unregister_chrdev(major, DEV_NAME);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



