
#目标:依赖
#	命令


#依赖的顺序与书写的顺序相关
#test3--> test2---> test1 --> all
all:test3 test2 test1
	@echo "------make all-------"

test1:
	@echo "------make test1------"

test2:
	@echo "------make test2------"

test3:
	@echo "------make test3------"
