
SRCS := add.c calc.c mult.c sub.c
PROG := calculator

CC := gcc
CFLAGS := -g

OBJS := $(SRCS:.c=.o)

$(PROG) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS) : numbers.h

.PHONY: clean
clean:
	-rm $(PROG)
	-rm -f *.o
