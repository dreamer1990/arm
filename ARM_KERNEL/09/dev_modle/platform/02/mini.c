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

#include "mini_device.h"

extern struct bus_type mini;

void mini_device_release(struct device *dev)
{}

int mini_device_register(struct mini_device *dev)
{
    dev->dev.init_name = dev->name;
    dev->dev.bus = &mini;
    dev->dev.release = mini_device_release;
    
    return device_register(&dev->dev);
}
EXPORT_SYMBOL(mini_device_register);

void mini_device_unregister(struct mini_device *dev)
{
    device_unregister(&dev->dev);
}
EXPORT_SYMBOL(mini_device_unregister);

int mini_probe(struct device *_dev)
{
    struct mini_device *mdev;
    struct mini_driver *mdrv;
    mdev = list_entry(_dev, struct mini_device, dev);
    mdrv = list_entry(_dev->driver, struct mini_driver, drv);

    return mdrv->probe(mdev);
}

int mini_remove(struct device *_dev)
{
    struct mini_device *mdev;
    struct mini_driver *mdrv;
    mdev = list_entry(_dev, struct mini_device, dev);
    mdrv = list_entry(_dev->driver, struct mini_driver, drv);
    
    return mdrv->remove(mdev);
}

int mini_driver_register(struct mini_driver *drv)
{
    drv->drv.name = drv->name;
    drv->drv.owner = drv->owner;
    drv->drv.bus = &mini;
    drv->drv.probe = mini_probe;
    drv->drv.remove = mini_remove;

    return driver_register(&drv->drv);
}
EXPORT_SYMBOL(mini_driver_register);

void mini_driver_unregister(struct mini_driver *drv)
{
    driver_unregister(&drv->drv);
}
EXPORT_SYMBOL(mini_driver_unregister);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



