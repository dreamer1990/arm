#ifndef __IOCTL_DEV__
#define __IOCTL_DEV__

#include <linux/ioctl.h>

#define WDT_TYPE    0x1

#define WDT_START       _IO(WDT_TYPE, 0)
#define WDT_STOP        _IO(WDT_TYPE, 1)
#define WDT_KEEPALIVE   _IO(WDT_TYPE, 2)
#define WDT_SETTIMEOUT  _IOW(WDT_TYPE, 3, int) 
#define WDT_SETIRQ      _IO(WDT_TYPE, 4)

#endif

