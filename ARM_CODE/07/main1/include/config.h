#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <type.h>

#define set_one(reg, num)   \
            *(v32 *)reg |= (1<<num)
#define set_zero(reg, num)   \
            *(v32 *)reg &= ~(1<<num)
#define set_bit(reg, num, val)   \
            *(v32 *)reg = ((*(v32 *)reg &~ (1<<num)) | ((val & 1) << num))
#define set_2bit(reg, num, val)   \
            *(v32 *)reg = ((*(v32 *)reg &~ (3<<num)) | ((val & 3) << num))
#define set_nbit(reg, num, n, val)   \
            *(v32 *)reg = ((*(v32 *)reg &~ (((1<<n)-1)<<num)) | ((val & ((1<<n)-1)) << num))
#define set_val(reg, val)   \
            *(v32 *)reg = val

#define get_bit(reg, num)   \
            (((*(v32 *)reg) & (1<<num))>>num)
#define get_2bit(reg, num)   \
            (((*(v32 *)reg) & (3<<num))>>num)
#define get_nbit(reg, num, n)   \
            (((*(v32 *)reg) & ( ((1<<n)-1) <<num))>>num)
#define get_val(reg)        \
            (*(v32 *)reg)

#endif

