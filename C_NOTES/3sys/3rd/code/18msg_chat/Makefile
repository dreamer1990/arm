
CC:=gcc
INC:= .
TARGET:= lucy tom jim  msgsnd
OBJS:=lucy.o jim.o tom.o  msgsnd.o


all:$(TARGET)
	@rm -rf $(OBJS)

lucy:lucy.o
	$(CC)  $< -o $@

jim:jim.o
	$(CC) $< -o $@

tom:tom.o
	$(CC) $< -o $@

msgsnd:msgsnd.o
	$(CC) $< -o $@

lucy.o:msgrcv.c
	gcc -c -DLUCY=3 $< -o $@
jim.o:msgrcv.c
	gcc -c -DJIM=2 $< -o $@
tom.o:msgrcv.c
	gcc -c -DTOM=1 $< -o $@

.PHONY:clean
clean:
	@rm -rf $(OBJS) $(TARGET)
	@rm -rf fifo*






