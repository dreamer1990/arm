#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEV_NAME    "test-dev"
#define MAX         1024

char dev_buf[MAX] = {};
int cur = 0;
void *reg_base;

int test_open(struct inode *inode, struct file *filp)
{
    printk("test open\n");
    printk("inode: %p filp: %p\n", inode, filp);
    printk("major: %d minor: %d\n", MAJOR(inode->i_rdev), MINOR(inode->i_rdev));

    return 0;
}

int test_close (struct inode *inode, struct file *filp)
{
    printk("test close\n");
    return 0;
}

ssize_t test_read(struct file *filp, char __user *buf, size_t size, loff_t *offset)
{
    int ret;
    printk("test read\n"); 
    if(*offset + size > cur)
        size = cur - *offset;

    //memcpy(buf, dev_buf + *offset, num);
    ret = copy_to_user(buf, dev_buf + *offset, size);
    *offset += size - ret;
    if(ret == size)
        return -EFAULT;
    return size - ret;
}

ssize_t test_write(struct file *filp, const char __user *buf, size_t size, loff_t *offset)
{
    int ret;
    printk("test write\n");   
    if(*offset + size > MAX)
        size = MAX - *offset;

    //memcpy(dev_buf + *offset, buf, num);
    ret = copy_from_user(dev_buf + *offset, buf, size);
    *offset += size - ret;
    cur += size - ret;
    if(ret == size)
        return -EFAULT;
    return size - ret;
}

loff_t test_lseek (struct file *filp, loff_t offset, int whence)
{
    loff_t tmp = filp->f_pos;
    switch(whence)
    {
        case SEEK_SET:
            tmp = offset;
            break;
        case SEEK_CUR:
            tmp += offset;
            break;
        case SEEK_END:
            tmp = MAX + offset;
            break;
    }

    if(tmp > MAX)
        tmp = MAX;

    filp->f_pos = tmp;
    return tmp;
}

struct file_operations fops = {
    .owner = THIS_MODULE, 
    .open = test_open, 
    .release = test_close,
    .read = test_read,
    .write = test_write,
    .llseek = test_lseek,
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



