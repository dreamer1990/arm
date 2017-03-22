
CC:=gcc
INC:= .
TARGET:= read write
OBJS:=read.o write.o


all:$(TARGET)
	@rm -rf $(OBJS)

read:read.o
	$(CC) $< -o $@
write:write.o
	$(CC) $< -o $@

read.o write.o:%.o:%.c
	@$(CC) -c $< -o $@

.PHONY:clean
clean:
	@rm -rf $(OBJS) $(TARGET)
	@rm -rf fifo






