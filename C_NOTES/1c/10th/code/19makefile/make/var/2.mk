CC := gcc
CFLAGS := -g
CCOMP = $(CC) $(CFLAGS)
# CCOMP := $(CC) $(CFLAGS)

$(info Compiler is $(CCOMP))

CC := arm-linux-gcc
$(info Compiler is $(CCOMP))

all:
	@echo execute finish.
