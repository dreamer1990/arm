
    .text
    .align  2
    .global delay
delay:
    subs r0, #1     @1GHZ   1000000000HZ -> 1ns     
    bne delay       @1GHZ                   1ns
    mov pc, lr
