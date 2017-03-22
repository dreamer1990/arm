#ifndef __MINI_DEVICE__
#define __MINI_DEVICE__

struct mini_test_info{
    int w;
    int h;
    int ch;
};

struct mini_device{
    char *name;
    struct device dev;
    struct resource *resources;
    int resource_num;
};

int mini_device_register(struct mini_device *);
void mini_device_unregister(struct mini_device *);

struct mini_driver{
    char *name;
    struct module *owner;
    struct device_driver drv;
    int (*probe)(struct mini_device *);
    int (*remove)(struct mini_device *);
};

int mini_driver_register(struct mini_driver *);
void mini_driver_unregister(struct mini_driver *);

#endif
