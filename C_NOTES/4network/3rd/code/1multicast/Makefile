TARGET= recv send
OBJS:= recv.o send.o 
CC:=gcc

all:$(TARGET)
recv:recv.o
	$(CC) $< -o $@
send:send.o
	$(CC) $< -o $@

%.o:%.c
	$(CC) -c $< -o $@

.PHONY:clean
clean:
	rm -rf *.o $(TARGET)

