
CC=gcc
INC= .
LIB_PATH= .
RM=rm -rf 
OBJS=stack.o test.o
TARGET=test


$(TARGET):$(OBJS)
	$(CC) -I$(INC) -L$(LIB_PATH) $^ -o $@
	@$(RM) $(OBJS)


%.o:%.c
	@$(CC) -c $< -o $@

.PHONY:clean
clean:
	@rm -rf $(TARGET) $(OBJS)



