    .text
    .align  2
    .global key_init
key_init:
    ldr r0, =0x11000C60
    ldr r1, [r0]
    ldr r2, =0xffff00
    bic r1, r1, r2
    str r1, [r0]
    mov pc, lr

    .align  2
    .global key_get
key_get:
    ldr r0, =0x11000C64
    ldr r0, [r0]
    mov r1, #(0xf<<2)
    and r0, r0, r1
    lsr r0, #2
    mov pc, lr
