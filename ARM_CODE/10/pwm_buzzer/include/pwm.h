#ifndef __PWM_H__
#define __PWM_H__

#define PWM_BASE        0x139D0000
#define TCFG0           (PWM_BASE+0x0)
#define TCFG1           (PWM_BASE+0x4)
#define TCON            (PWM_BASE+0x8)
#define TCNTB0          (PWM_BASE+0xc)
#define TCMPB0          (PWM_BASE+0x10)
#define TCNTO0          (PWM_BASE+0x14)
#define TCNTB4          (PWM_BASE+0x3c)
#define TCNTO4          (PWM_BASE+0x40)
#define TINT_CSTAT      (PWM_BASE+0x44)

#endif
