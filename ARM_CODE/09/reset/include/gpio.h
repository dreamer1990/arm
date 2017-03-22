#ifndef __GPIO_H__
#define __GPIO_H__

#define GPM4CON     0x110002E0
#define GPM4DAT     0x110002E4
#define GPD0CON     0x114000A0
#define GPD0DAT     0x114000A4
#define GPX3CON     0x11000C60
#define GPX3DAT     0x11000C64

//#define GPM4CON     (*(volatile unsigned int *)0x110002E0)
/*
struct gpio_base{
    unsigned int GPA0CON;
    unsigned int GPA0DAT;
    ...
    unsigned int reg[2];
    unsigned int GPA1CON;
    //......
};
struct gpio_base *gpio = (void *)0x11400000
gpio->GPA0CON = 
gpio->GPA0DAT = 
*/

#endif
