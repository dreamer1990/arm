
CC:=gcc
INC:= .
TARGET:= msgrcv msgsnd
OBJS:=msgrcv.o msgsnd.o


all:$(TARGET)
	@rm -rf $(OBJS)

msgrcv:msgrcv.o
	$(CC) $< -o $@
msgsnd:msgsnd.o
	$(CC) $< -o $@

msgrcv.o msgsnd.o:%.o:%.c
	@$(CC) -c $< -o $@

.PHONY:clean
clean:
	@rm -rf $(OBJS) $(TARGET)
	@rm -rf fifo*






