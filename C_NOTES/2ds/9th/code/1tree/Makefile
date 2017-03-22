
TARGET:=test
OBJS:= tree.o test.o
CC:=gcc
INC:=.
LIB_PATH=.


$(TARGET):$(OBJS)
	$(CC) $^ -o $@
	$(RM) -rf $(OBJS)

%.o:%.c
	$(CC) -c $< -o $@

.PHONY:clean
clean:
	rm -rf $(TARGET)
