    
    .text
    .align  2
    .global _start
_start:
    stmfd sp!, {lr}

    ldr r1, =0x10000000
    ldr r1, [r1]
    adr r0, .LC0    @.LC0汇编时的相对地址; pc+;与地址无关指令;
    mov lr, pc
    ldr pc, =0x43e11a2c

    ldmfd sp!, {pc}

    .align  2
.LC0:
    .string "chip_id = %p\n"
    .align  2

