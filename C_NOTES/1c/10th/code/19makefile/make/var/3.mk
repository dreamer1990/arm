
foo := a.o b.o c.o
var := $(foo:.o=.c)

all:
# 注意makefile中一定要以$(var)或者${var}
# 的形式引用变量
	@echo foo = $foo
	@echo foo = $(foo)
	@echo foo = ${foo}
	@echo var = $(var)
