#ifndef __GIC_H__
#define __GIC_H__

#define ICCICR_CPUn      0x10480000
#define ICCICR_CPU(n)   (ICCICR_CPUn + n*0x4000)
#define ICCPMR_CPUn      0x10480004
#define ICCPMR_CPU(n)   (ICCPMR_CPUn + n*0x4000)
#define ICCIAR_CPUn      0x1048000c
#define ICCIAR_CPU(n)   (ICCIAR_CPUn + n*0x4000)
#define ICCEOIR_CPUn     0x10480010
#define ICCEOIR_CPU(n)  (ICCEOIR_CPUn+ n*0x4000)

#define ICDDCR          0x10490000
#define ICDISER_CPUn     0x10490100
#define ICDISER_CPU(n, m)   (ICDISER_CPUn + n*0x4000 + m*4)
#define ICDICER_CPUn     0x10490180
#define ICDICER_CPU(n, m)   (ICDICER_CPUn + n*0x4000 + m*4)
#define ICDIPR_CPUn      0x10490400
#define ICDIPR_CPU(n, m)    (ICDIPR_CPUn + n*0x4000 + m*4)
#define ICDIPTR_CPUn     0x10490800
#define ICDIPTR_CPU(n, m)   (ICDIPTR_CPUn+ n*0x4000 + m*4)
#define ICDSGIR         0x10490F00

#endif

