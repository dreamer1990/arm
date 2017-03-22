#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/sched.h>
#include <linux/poll.h>
#include "ioctl-dev.h"

#define DEV_NAME    "test-dev"
#define MAX         1024

struct test_dev {
    char dev_buf[MAX];
    int cur;
    int offset;

    void *reg_base;
    u32 gpio_irq;

    struct file_operations fops;
    int major;
};

volatile bool empty = true;

wait_queue_head_t wq;
struct fasync_struct *fapp; //异步队列头; 无头节点的单项不循环链表;
spinlock_t slock;       //定义自旋锁;

////////////////////////chrdev//////////////////////////
int test_open(struct inode *inode, struct file *filp)
{
    struct test_dev *tdev;
    struct task_struct *task;
    struct thread_info *thread;
    //int stack;
    tdev = container_of(filp->f_op, struct test_dev, fops);
    filp->private_data = tdev;
    printk("test open\n");

    task = current;
    printk("pid: %d comm: %s\n", task->pid, task->comm);

    //thread = (struct thread_info *)(((unsigned long)&stack) &~ (THREAD_SIZE - 1));
    thread = current_thread_info();

    printk("cpu: %d pid: %d comm: %s\n", thread->cpu, thread->task->pid, thread->task->comm);

    return 0;
}

int test_close (struct inode *inode, struct file *filp)
{
    //struct test_dev *tdev = filp->private_data;
    printk("test close\n");
    return 0;
}

ssize_t test_read(struct file *filp, char __user *buf, size_t size, loff_t *offset)
{
    struct test_dev *tdev = filp->private_data;
    int ret;
    printk("test read\n"); 

    spin_lock(&slock);  //加自旋锁, 加锁失败, 循环等待;
    if(tdev->offset == tdev->cur)
        empty = true;

    while(empty)
    {
        spin_unlock(&slock);
        if(filp->f_flags & O_NONBLOCK)
        {
            return 0;   
        }

        wait_event(wq, !empty);
        //if(wait_event_interruptible(wq, !empty))
        //if(wait_event_interruptible_exclusive(wq, !empty))
        //{
        //    return -ERESTARTSYS; 
        //}
        printk("wake up\n");
        spin_lock(&slock);
    }

    if(tdev->offset + size > tdev->cur)
        size = tdev->cur - tdev->offset;

    //memcpy(buf, dev_buf + tdev->offset, num);
    ret = copy_to_user(buf, tdev->dev_buf + tdev->offset, size);
    tdev->offset += size - ret;
    printk("ret : %d size : %u buf: %s\n", ret, size, buf);

    if(tdev->offset == tdev->cur)
        empty = true;

    spin_unlock(&slock);

    if(ret == size)
        return -EFAULT;
    return size - ret;
}

ssize_t test_write(struct file *filp, const char __user *buf, size_t size, loff_t *offset)
{
    struct test_dev *tdev = filp->private_data;
    int ret;
    printk("test write\n");   
    spin_lock(&slock);
    if(tdev->cur + size > MAX)
        size = MAX - tdev->cur;

    //memcpy(dev_buf + *offset, buf, num);
    ret = copy_from_user(tdev->dev_buf + tdev->cur, buf, size);
    //*offset += size - ret;
    tdev->cur += size - ret;
    printk("ret: %d size: %u\n", ret, size);
    if(ret == size)
    {
        spin_unlock(&slock);
        return -EFAULT;
    }

    if(size - ret != 0)
    {
        empty = false;
        spin_unlock(&slock);
        wake_up(&wq);
        //wake_up_interruptible(&wq);
        //wake_up_interruptible_nr(&wq, 1);
        kill_fasync(&fapp, SIGIO, POLL_IN);
    }
    else
    {
        spin_unlock(&slock);
    }


    return size - ret;
}

loff_t test_lseek (struct file *filp, loff_t offset, int whence)
{
    //struct test_dev *tdev = filp->private_data;
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

long test_ioctl (struct file *filp, unsigned int cmd, unsigned long arg)
{
    struct led_set *lset;
    //struct test_dev *tdev = filp->private_data;
    
    if(_IOC_TYPE(cmd) != LED_TYPE)
    {
        return -EINVAL;
    }

    switch(cmd)
    {
        case LED_ON:
            printk("led on\n");
            //gpio_direction_output();
            break;
        case LED_OFF:
            printk("led off\n");
            //gpio_direction_output();
            break;
        case LED_SET:
            printk("set led %lu\n", arg);
            break;
        case LED_SETON:
            lset = (void *)arg;
            printk("led_num: %d led_flag: %d\n", lset->led_num, lset->led_flag);
            break;
    }
    
    return 0;
}

unsigned int test_poll(struct file *filp, struct poll_table_struct *ptable)
{
    printk("test poll\n");
    poll_wait(filp, &wq, ptable);   //select/poll加入当前驱动的wq;
                                    //__pollwait
    if(!empty)
        return POLLIN;
    else
        return 0;
}

int test_fasync(int fd, struct file *filp, int on)
{
    printk("test fasync on: %d\n", on);
    return fasync_helper(fd, filp, on, &fapp); //加入或者拔出异步队列;
}

///////////////////////////module///////////////////////////////////
struct test_dev tdev = {
    .fops = {
        .owner = THIS_MODULE, 
        .open = test_open, 
        .release = test_close,
        .read = test_read,
        .write = test_write,
        .llseek = test_lseek,
        .unlocked_ioctl = test_ioctl,
        .poll = test_poll,       
        .fasync = test_fasync,
    },
    .major = 0,
};

int test_init(void)
{
    int ret;
    printk("test init\n");
    ret = register_chrdev(tdev.major, DEV_NAME, &tdev.fops);
    if(ret < 0)
    {
        return ret;
    }
    if(tdev.major == 0)      //动态申请到主设备号;
    {
        tdev.major = ret;
    }
    printk("major : %d\n", tdev.major);

    init_waitqueue_head(&wq);

    spin_lock_init(&slock);
    
    return 0;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    unregister_chrdev(tdev.major, DEV_NAME);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



