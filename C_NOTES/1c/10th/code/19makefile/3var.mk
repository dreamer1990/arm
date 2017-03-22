
     #变量定义:
     #--------------------------------
     #延后赋值: 变量被引用时才赋值
     #var = str
     
     #立即赋值
     #var := str
     
     #追加赋值: 给变量追加值, 如果变量原来是立即赋值的,
     #则追加也是立即的; 否则为延后追加赋值.
     #var += str
     
     #条件赋值: 变量没有定义则使用该赋值.
     #var ?= str
     
#延后赋值
var = test.c

#立即赋值
var1 := test1
var1 +=  test2

#如果var1没有定义,则使用该赋值
var1 ?= test3

var2 ?= test2 test3 test4

all:
	@echo ${var}
	@echo $(var)
	@echo $(var1)
	@echo $(var2)
     
