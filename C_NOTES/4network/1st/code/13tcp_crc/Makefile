TARGET:= server client
OBJS:= server.o client.o 
CC:=gcc

all:$(TARGET)
server:server.o crc.o
	$(CC) $^ -o $@
client:client.o crc.o
	$(CC) $^ -o $@

%.o:%.c
	$(CC) -c $< -o $@

.PHONY:clean
clean:
	rm -rf *.o $(TARGET)

