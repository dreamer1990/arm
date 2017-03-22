
.global  start
start:
	
	@异常向量表
	b	Reset
	b	Undef
	b	Svc
	b	PrefecthAbt
	b	DataAbt
	nop  @==> mov r0 , r0
	b	irq 
	b	fiq

Reset:
	stmfd sp! , {r0-r12 , lr}

	ldr	r0 , =0x62000000
	ldr	r0 , [r0]
	mov	lr , pc
	mov	pc , r0

	ldmfd sp! , {r0-r12 , pc}^

Undef:
	stmfd sp! , {r0-r12 , lr}

	ldr	r0 , =0x62000004
	ldr	r0 , [r0]
	mov	lr , pc
	mov	pc , r0

	ldmfd sp! , {r0-r12 , pc}^

Svc:
	stmfd sp! , {r0-r12 , lr}

	ldr	r0 , =0x62000008
	ldr	r0 , [r0]
	mov	lr , pc
	mov	pc , r0

	ldmfd sp! , {r0-r12 , pc}^
PrefecthAbt:
	stmfd sp! , {r0-r12 , lr}

	ldr	r0 , =0x6200000C
	ldr	r0 , [r0]
	mov	lr , pc
	mov	pc , r0

	ldmfd sp! , {r0-r12 , pc}^
DataAbt:
	stmfd sp! , {r0-r12 , lr}

	ldr	r0 , =0x62000010
	ldr	r0 , [r0]
	mov	lr , pc
	mov	pc , r0

	ldmfd sp! , {r0-r12 , pc}^
irq:
	sub	lr , #4
	stmfd sp! , {r0-r12 , lr}

	ldr	r0 , =0x62000014
	ldr	r0 , [r0]
	mov	lr , pc
	mov	pc , r0

	ldmfd sp! , {r0-r12 , pc}^
fiq:
	sub	lr , #4
	stmfd sp! , {r0-r12 , lr}

	ldr	r0 , =0x62000018
	ldr	r0 , [r0]
	mov	lr , pc
	mov	pc , r0

	ldmfd sp! , {r0-r12 , pc}^

.global end
end:

