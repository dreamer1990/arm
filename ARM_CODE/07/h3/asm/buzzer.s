
    .text
    .align  2
    .global buzzer_init
buzzer_init:
    ldr r0, =0x114000A0
    ldr r1, [r0]
    bic r1, r1, #0xf
    orr r1, r1, #0x1
    str r1, [r0]
    mov pc, lr

    .align  2
    .global buzzer_on
buzzer_on:
    ldr r0, =0x114000A4
    ldr r1, [r0]
    orr r1, r1, #1
    str r1, [r0]
    mov pc, lr

    .align  2
    .global buzzer_off
buzzer_off:
    ldr r0, =0x114000A4
    ldr r1, [r0]
    bic r1, r1, #1
    str r1, [r0]
    mov pc, lr
    
