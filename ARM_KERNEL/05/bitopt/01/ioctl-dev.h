#ifndef __IOCTL_DEV__
#define __IOCTL_DEV__

#include <linux/ioctl.h>

#define BZ_TYPE    0x1


#define BZ_ON      _IO(BZ_TYPE, 0)
#define BZ_OFF     _IO(BZ_TYPE, 1)

#endif

