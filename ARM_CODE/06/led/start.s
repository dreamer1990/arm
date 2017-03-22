    
    .text
    .align  2
    .global _start
_start:
    stmfd sp!, {lr}
	
    @配置成输出; 
    ldr r0, =0x110002E0
    ldr r1, [r0]
    ldr r2, =0xffff
    bic r1, r1, r2
    ldr r2, =0x1111
    orr r1, r1, r2
    str r1, [r0]

    @输出低电平全亮;
    ldr r0, =0x110002E4
    ldr r1, [r0]
    bic r1, r1, #0xf
    str r1, [r0]

    ldmfd sp!, {pc}


