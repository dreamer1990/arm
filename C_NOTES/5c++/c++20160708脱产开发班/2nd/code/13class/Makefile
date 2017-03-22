
OBJS:= time.o test.o
TARGET := test
CC := g++
INC:= .

all: $(TARGET)

$(TARGET):$(OBJS)
	$(CC) -I$(INC) $^ -o $@

%.o:%.c
	$(CC) -c $< -o $@

.PHONY:clean
clean:
	rm  -rf $(OBJS) $(TARGET)
