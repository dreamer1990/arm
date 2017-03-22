TARGET:=test
CC:=gcc
OBJS:=test.o 
INC:= .
LIB_PATH:= .
#RM:=rm -rf

$(TARGET):$(OBJS)
	$(CC) -I$(INC) -L$(LIB_PATH) $^ -o $@
	@$(RM) $(OBJS)

%.o:%.c
	@$(CC) -c $< -o $@


.PHONY:clean
clean:
	rm -rf $(TARGET)

