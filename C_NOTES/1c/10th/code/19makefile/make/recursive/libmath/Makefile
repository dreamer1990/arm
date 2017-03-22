
SRCS := clock.c letter.c number.c add.c sub.c mult.c
LIB := libmath.a

CC := gcc
CFLAGS := -g

OBJS := $(SRCS:.c=.o)

$(LIB) : $(OBJS)
	$(AR) cr $(LIB) $(OBJS)

$(OBJS)	: math.h

.PHONY: clean
clean:
	rm -f $(OBJS) $(LIB)
