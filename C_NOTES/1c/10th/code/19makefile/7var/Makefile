
#隐式规则
TARGET := test
OBJS := test.o a.o b.o



all:$(OBJS)
	gcc $(OBJS) -o $(TARGET)

#使用隐式目标 eg: cc test.c -c -o test.o
test.o:test.c
a.o:a.c
b.o:b.c

.PHOYN:clean
clean:
	@#以下两种方式等价
	@#rm -rf $(OBJS) $(TARGET)
	rm -rf *.o test

	

