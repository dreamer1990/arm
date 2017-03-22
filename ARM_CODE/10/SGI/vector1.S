
    .section    .rodata
    .align  2
.LC0:
    .string "cpsr : %x\n"
    .align  2
.LC1:
    .string "system call num : %d\n"
    .align  2
.LC2:
    .string "lr : %p\n"

    .text
    .align  2
    .global vector_start
vector_start:
    b   reset       @复位异常入口; 0x0
    b   undef       @0x4
    b   swi         @0x8
    b   pabort      @0xc
    b   dabort      @0x10
    nop             @0x14
    b   irq         @0x18
    b   firq        @0x1c

reset:
    b   reset

undef:
    mov sp, #0x7f000000
    stmfd sp!, {r0-r12, lr}

    mrs r1, cpsr
    ldr r0, .L0
    mov lr, pc
    ldr pc, .L0+4   @调用u-boot函数   @bl printf  调用c库的函数;

    ldmfd sp!, {r0-r12, pc}^    @^ : cpsr = spsr

swi:
    stmfd sp!, {r0-r12, lr}

    sub r1, lr, #4      @swi指令地址;
    ldr r1, [r1]        @指令编码;
    bic r1, r1, #0xff000000     @保留低位;
    ldr r0, .L0+8
    mov lr, pc
    ldr pc, .L0+4   @调用u-boot函数   @bl printf  调用c库的函数;

    mrs r1, cpsr
    ldr r0, .L0
    mov lr, pc
    ldr pc, .L0+4   @调用u-boot函数   @bl printf  调用c库的函数;

    ldmfd sp!, {r0-r12, lr}
    movs pc, lr     @s: cpsr <- spsr (回到之前模式)

pabort:
    mov sp, #0x7f000000
    stmfd sp!, {r0-r12, lr}

    mrs r1, cpsr
    ldr r0, .L0
    mov lr, pc
    ldr pc, .L0+4   @调用u-boot函数   @bl printf  调用c库的函数;

    ldmfd sp!, {r0-r12, lr}
    @subs pc, lr, #4
    movs pc, lr

dabort:
    mov sp, #0x7f000000
    stmfd sp!, {r0-r12, lr}

    mov r1, lr
    ldr r0, .L0+12
    mov lr, pc
    ldr pc, .L0+4

    mrs r1, cpsr
    ldr r0, .L0
    mov lr, pc
    ldr pc, .L0+4   @调用u-boot函数   @bl printf  调用c库的函数;

    ldmfd sp!, {r0-r12, lr}
    subs pc, lr, #4

irq:
    mov sp, #0x7f000000
    stmfd sp!, {r0-r12, lr}

    mrs r1, cpsr
    ldr r0, .L0
    mov lr, pc
    ldr pc, .L0+4   @调用u-boot函数   @bl printf  调用c库的函数;

    @bl  do_sgi

    mov lr, pc
    ldr pc, .L0+16

    ldmfd sp!, {r0-r12, lr}
    subs pc, lr, #4

firq:

    b   firq

.L0:
    .word   .LC0
    .word   0x43e11a2c
    .word   .LC1
    .word   .LC2
    .word   do_sgi

    .align  2
    .global vector_end
vector_end:
    

