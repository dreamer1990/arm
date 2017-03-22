    
    .text
    .align  2
    .global _start
_start:
    stmfd sp!, {lr}

    @ldr r0, =.LC0  @.LC0链接时替换成绝对地址; 与地址相关指令;
    adr r0, .LC0    @.LC0汇编时的相对地址; pc+;与地址无关指令;
    mov lr, pc
    ldr pc, =0x43e11a2c

    ldmfd sp!, {pc}

    .align  2
.LC0:
    .string "hello world\n"
    .align  2

