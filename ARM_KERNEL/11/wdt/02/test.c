#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
//#include <linux/vmalloc.h>
//#include <linux/pagemap.h>
#include <linux/io.h>
//#include <linux/io-mapping.h>
#include <linux/device.h>
#include <linux/miscdevice.h>
#include <linux/platform_device.h>
#include <linux/clk.h>

//#include <plat/map-base.h>

#undef  S3C_VA_WATCHDOG
#define S3C_VA_WATCHDOG 0

#include <plat/regs-watchdog.h>

#include "ioctl-dev.h"

#define DRV_NAME    "test-wdt"

struct test_wdt_device{
    struct platform_device *pdev;
    void __iomem *reg_base;
    int reg_size;
    int irq;
    struct clk *wdt_clk;
    
    unsigned int wddat;
    unsigned int wdcnt;
    unsigned int timeout;

    struct file_operations fops;
    struct miscdevice mdev;
};

void wdt_start(struct test_wdt_device* tdev)
{
    unsigned int val = ioread32(tdev->reg_base + (int)S3C2410_WTCON);
    printk("wdt start\n");
    val |= S3C2410_WTCON_DIV128 | S3C2410_WTCON_ENABLE | S3C2410_WTCON_RSTEN;
    iowrite32(val, tdev->reg_base + (int)S3C2410_WTCON);   
}

void wdt_stop(struct test_wdt_device* tdev)
{
    unsigned int val = ioread32(tdev->reg_base + (int)S3C2410_WTCON);
    printk("wdt stop\n");
    val &= ~(S3C2410_WTCON_ENABLE | S3C2410_WTCON_RSTEN);
    iowrite32(val, tdev->reg_base + (int)S3C2410_WTCON);   
}

void wdt_keepalive(struct test_wdt_device* tdev)
{
    printk("wdt keepalive\n");
    iowrite32(tdev->wdcnt, tdev->reg_base + (int)S3C2410_WTCNT);
}

int wdt_settimeout(struct test_wdt_device* tdev, int timeout)
{
    unsigned long freq = clk_get_rate(tdev->wdt_clk);
    unsigned int count;
    unsigned int divisor = 1;
    unsigned long wtcon;
    printk("wdt settimeout: %d\n", timeout);

    if (timeout < 1)
        return -EINVAL;
    
    freq /= 128;
    count = timeout * freq;

    if (count >= 0x10000) {
        for (divisor = 1; divisor <= 0x100; divisor++) {
            if ((count / divisor) < 0x10000)
                break;
        }

        if ((count / divisor) >= 0x10000) {
            return -EINVAL;
        }
    }

    count /= divisor;
    //printk("count: %d divisor: %d\n", count, divisor);
    tdev->wdcnt = count;

    wtcon = ioread32(tdev->reg_base + (int)S3C2410_WTCON);
    wtcon &= ~S3C2410_WTCON_PRESCALE_MASK;
    wtcon |= S3C2410_WTCON_PRESCALE(divisor-1);

    iowrite32(count, tdev->reg_base + (int)S3C2410_WTDAT);
    iowrite32(count, tdev->reg_base + (int)S3C2410_WTCNT);
    iowrite32(wtcon, tdev->reg_base + (int)S3C2410_WTCON);

    tdev->timeout = (count * divisor) / freq;
    return 0;
}

void wdt_init(struct test_wdt_device* tdev)
{
    unsigned int val = ioread32(tdev->reg_base + (int)S3C2410_WTCON);
    iowrite32(tdev->wddat, tdev->reg_base + (int)S3C2410_WTDAT);
    iowrite32(tdev->wdcnt, tdev->reg_base + (int)S3C2410_WTCNT);
    val |= S3C2410_WTCON_DIV128;
    iowrite32(val, tdev->reg_base + (int)S3C2410_WTCON);   
}

void wdt_setirq(struct test_wdt_device *tdev)
{
    unsigned int val = ioread32(tdev->reg_base + (int)S3C2410_WTCON);
    printk("wdt setirq\n");
    val &= ~S3C2410_WTCON_RSTEN;
    val |= S3C2410_WTCON_INTEN | S3C2410_WTCON_ENABLE;
    iowrite32(val,  tdev->reg_base + (int)S3C2410_WTCON);   
}

long test_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    struct test_wdt_device *tdev= container_of(filp->f_op, struct test_wdt_device, fops);
    switch(cmd)
    {
        case WDT_START:
            wdt_start(tdev); 
            break;
        case WDT_STOP:
            wdt_stop(tdev);
            break;
        case WDT_KEEPALIVE:
            wdt_keepalive(tdev);
            break;
        case WDT_SETTIMEOUT:
            wdt_settimeout(tdev, arg);
            break;
        case WDT_SETIRQ:
            wdt_setirq(tdev);
            break;
        default:
            break;
    }
    return 0;
}

irqreturn_t wdt_handler(int irq, void *data)
{
    struct test_wdt_device *tdev = data;
    printk("wdt time out\n");
    iowrite32(0, tdev->reg_base + 0xc);
    return IRQ_HANDLED;
}

int test_probe (struct platform_device *dev)
{
    int ret;
    struct resource *res;
    struct test_wdt_device *tdev;
    printk("test drv probe: devname: %s\n", dev->name);

    tdev = kzalloc(sizeof(struct test_wdt_device), GFP_KERNEL);
    if(IS_ERR_OR_NULL(tdev))
    {
        ret = -ENOMEM;
        goto ERROR_kzalloc;
    }

    platform_set_drvdata(dev, tdev);
    
    res = platform_get_resource(dev, IORESOURCE_MEM, 0); 
    if(IS_ERR_OR_NULL(res))
    {
        ret = -ENOMEM;
        goto ERROR_get_resource_mem;
    }
    
    tdev->reg_size = resource_size(res);
    tdev->reg_base = ioremap(res->start, tdev->reg_size);
    if(IS_ERR_OR_NULL(tdev->reg_base))
    {
        ret = -ENOMEM;
        goto ERROR_ioremap;
    }

    res = platform_get_resource(dev, IORESOURCE_IRQ, 0);
    if(IS_ERR_OR_NULL(res))
    {
        ret = -EBUSY;
        goto ERROR_get_resource_irq;
    }

    tdev->irq = res->start;
    ret = request_irq(res->start, wdt_handler, IRQF_TRIGGER_NONE, 
            DRV_NAME, tdev);
    if(IS_ERR_VALUE(ret))
    {
        goto ERROR_request_irq;
    }

    tdev->pdev = dev;
    //tdev->wdt_clk = clk_get(&dev->dev, "watchdog");
    tdev->wdt_clk = clk_get(NULL, "watchdog");
    if(IS_ERR_OR_NULL(tdev->wdt_clk))
    {
        ret = -EBUSY;
        goto ERROR_clk_get;
    }

    clk_enable(tdev->wdt_clk);
    
    tdev->wddat = 0xffff;
    tdev->wdcnt = 0xffff;
    wdt_init(tdev);

    tdev->fops.owner = THIS_MODULE;
    tdev->fops.unlocked_ioctl = test_ioctl;

    tdev->mdev.name = DRV_NAME;
    tdev->mdev.minor = MISC_DYNAMIC_MINOR;
    tdev->mdev.fops = &tdev->fops;

    ret = misc_register(&tdev->mdev);
    if(IS_ERR_VALUE(ret))
    {
        goto ERROR_misc_register;
    }
    
    return 0;
ERROR_misc_register:
    clk_disable(tdev->wdt_clk);
    clk_put(tdev->wdt_clk);
ERROR_clk_get:
    free_irq(tdev->irq, tdev);
ERROR_request_irq:
ERROR_get_resource_irq:
    iounmap(tdev->reg_base);
ERROR_ioremap:
ERROR_get_resource_mem:
    kfree(tdev);
ERROR_kzalloc:
    return ret;
}

int test_remove (struct platform_device *dev)
{
    struct test_wdt_device *tdev = platform_get_drvdata(dev);
    printk("test drv remove: devname: %s\n", dev->name);
    wdt_stop(tdev);
    misc_deregister(&tdev->mdev);
    clk_disable(tdev->wdt_clk);
    clk_put(tdev->wdt_clk);
    free_irq(tdev->irq, tdev);
    iounmap(tdev->reg_base);
    kfree(tdev);
    return 0;
}

struct platform_device_id id_table[] = {
    {"s3c2410-wdt", 0},
//    {"test-adc", 1},
//    {"test-abc", 2},
//    {"test-led", 3},
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



