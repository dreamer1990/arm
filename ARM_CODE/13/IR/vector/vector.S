
.global  _start
_start:
	
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


	ldmfd sp! , {r0-r12 , pc}^

Undef:
	stmfd sp! , {r0-r12 , lr}

	ldr	r0 , =Str
	ldr	r1 , =0x43E11A2C
	mov	lr , pc
	mov	pc , r1

	ldmfd sp! , {r0-r12 , pc}^

Svc:
	stmfd sp! , {r0-r12 , lr}


	ldmfd sp! , {r0-r12 , pc}^
PrefecthAbt:
	stmfd sp! , {r0-r12 , lr}


	ldmfd sp! , {r0-r12 , pc}^
DataAbt:
	stmfd sp! , {r0-r12 , lr}


	ldmfd sp! , {r0-r12 , pc}^
irq:
	stmfd sp! , {r0-r12 , lr}


	ldmfd sp! , {r0-r12 , pc}^
fiq:
	stmfd sp! , {r0-r12 , lr}


	ldmfd sp! , {r0-r12 , pc}^


Str:
	.string  "hello kitty \n"
	.align  2

