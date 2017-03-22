TARGET:= server client
OBJS:= server.o client.o  cJSON.o
CC:=gcc
CFLAG:= -lm
all:$(TARGET)
server:server.o cJSON.o
	$(CC)  $(CFLAG) $^ -o $@
client:client.o cJSON.o
	$(CC) $(CFLAG) $^ -o $@

%.o:%.c
	$(CC) -c $< -o $@

.PHONY:clean
clean:
	rm -rf *.o $(TARGET)

