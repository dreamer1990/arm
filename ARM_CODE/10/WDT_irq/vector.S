
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
    ldr pc,   _reset       @复位异常入口; 0x0
    ldr pc,   _undef       @0x4
    ldr pc,   _swi         @0x8
    ldr pc,   _pabort      @0xc
    ldr pc,   _dabort      @0x10
    nop             @0x14
    ldr pc,   _irq         @0x18
    ldr pc,   _firq        @0x1c

_reset:
    .word   reset
_undef:
    .word   undef
_swi:
    .word   swi
_pabort:
    .word   pabort
_dabort:
    .word   dabort
_irq:
    .word   irq
_firq:
    .word   firq

    .align  2
    .global vector_end
vector_end:

reset:
    b   reset

undef:
    mov sp, #0x7f000000
    stmfd sp!, {r0-r12, lr}

    mrs r1, cpsr
    ldr r0, =.LC0
    mov lr, pc
    ldr pc, =0x43e11a2c

    ldmfd sp!, {r0-r12, pc}^    @^ : cpsr = spsr

swi:
    stmfd sp!, {r0-r12, lr}

    sub r1, lr, #4      @swi指令地址;
    ldr r1, [r1]        @指令编码;
    bic r1, r1, #0xff000000     @保留低位;
    ldr r0, =.LC1
    mov lr, pc
    ldr pc, =0x43e11a2c   @调用u-boot函数   @bl printf  调用c库的函数;

    mrs r1, cpsr
    ldr r0, =.LC0
    mov lr, pc
    ldr pc, =0x43e11a2c   @调用u-boot函数   @bl printf  调用c库的函数;

    ldmfd sp!, {r0-r12, lr}
    movs pc, lr     @s: cpsr <- spsr (回到之前模式)

pabort:
    mov sp, #0x7f000000
    stmfd sp!, {r0-r12, lr}

    mrs r1, cpsr
    ldr r0, =.LC0
    mov lr, pc
    ldr pc, =0x43e11a2c   @调用u-boot函数   @bl printf  调用c库的函数;

    ldmfd sp!, {r0-r12, lr}
    @subs pc, lr, #4
    movs pc, lr

dabort:
    mov sp, #0x7f000000
    stmfd sp!, {r0-r12, lr}

    mov r1, lr
    ldr r0, =.LC2
    mov lr, pc
    ldr pc, =0x43e11a2c

    mrs r1, cpsr
    ldr r0, =.LC0
    mov lr, pc
    ldr pc, =0x43e11a2c   @调用u-boot函数   @bl printf  调用c库的函数;

    ldmfd sp!, {r0-r12, lr}
    subs pc, lr, #4

irq:
    mov sp, #0x7f000000
    stmfd sp!, {r0-r12, lr}

    mrs r1, cpsr
    ldr r0, =.LC0
    mov lr, pc
    ldr pc, =0x43e11a2c   @调用u-boot函数   @bl printf  调用c库的函数;

    bl  do_irq

    ldmfd sp!, {r0-r12, lr}
    subs pc, lr, #4

firq:
    b   firq


