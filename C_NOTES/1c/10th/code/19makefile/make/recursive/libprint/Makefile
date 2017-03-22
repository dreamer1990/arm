
SRCS := file.c normal.c center.c
LIB := libprint.a

CC := gcc
CFLAGS := -g

OBJS := $(SRCS:.c=.o)

$(LIB) : $(OBJS)
	$(AR) cr $(LIB) $(OBJS)
	$(MAKE) -C pppp

$(OBJS)	: print.h

.PHONY: clean
clean:
	rm -f $(OBJS) $(LIB)
