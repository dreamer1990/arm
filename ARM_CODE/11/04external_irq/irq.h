
#ifndef _IRQ_H
#define _IRQ_H

#include "res.h"


void vector_copy(void);
void enable_cpsr_I(void);
void enable_internal_irq(int irqid);
void Send_internal_irq(int irqid);


#endif  //_IRQ_H

