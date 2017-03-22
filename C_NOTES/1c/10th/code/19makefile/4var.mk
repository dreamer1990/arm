
#执行默认的目标
#make -f 4var.mk
#执行指定的目标
#make test -f 4var.mk

#目标一定要顶格写,命令至少要加一个tab键
#目标:依赖
#	命令

#多个依赖

#如果一个目标被依赖多次,则只会执行一次

#all目标依赖test1 和 test2
all: test1 test2
	@echo "---> all"

#目标test1依赖test
test1:test
	@echo "---> test1"
#目标test2依赖test
test2:test
	@echo "---> test2"
#目标test没有依赖
test:
	@echo "---> test"
