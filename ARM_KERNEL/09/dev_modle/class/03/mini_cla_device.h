#ifndef __MINI_CLA_DEVICE__
#define __MINI_CLA_DEVICE__

#include <linux/device.h>

struct mini_cla_device {
    char *name;
    struct device dev;
};

int mini_class_device_register(struct mini_cla_device *);
void mini_class_device_unregister(struct mini_cla_device *);

#endif
