TARGET:=test
CC:=gcc
OBJS:= test.o slist.o
INC:= .
LIB_PATH:= .
RM:= rm -rf

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) -I$(INC) -L$(LIB_PATH) $^ -o $@
	@$(RM)	$(OBJS)

%.o:%.c
	@$(CC) -c $< -o $@

.PHONY:clean
clean:
	rm -rf $(TARGET)
	rm -rf txt



