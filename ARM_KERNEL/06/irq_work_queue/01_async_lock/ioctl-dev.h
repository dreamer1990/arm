#ifndef __IOCTL_DEV__
#define __IOCTL_DEV__

#include <linux/ioctl.h>

#define LED_TYPE    0x1

struct led_set {
    int led_num;
    int led_flag;
};

#define LED_ON      _IO(LED_TYPE, 0)
#define LED_OFF     _IO(LED_TYPE, 1)
#define LED_SET     _IOW(LED_TYPE, 2, int)
#define LED_SETON   _IOW(LED_TYPE, 3, struct led_set *) 

#endif

