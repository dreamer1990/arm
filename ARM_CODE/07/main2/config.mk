
CC = $(CROSS_COMPILE)gcc
CC_FLAGS = -c -I $(TOPDIR)/include -O3 
LD = $(CROSS_COMPILE)ld
LD_FLAGS = 
OBJDUMP = $(CROSS_COMPILE)objdump
OBJDUMP_FLAGS = -D
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJCOPY_FLAGS = -O binary
AR = $(CROSS_COMPILE)ar
AR_FLAGS = crv

%.o:%.s
	$(CC) $(CC_FLAGS) $< 
%.o:%.S
	$(CC) $(CC_FLAGS) $< 
%.o:%.c
	$(CC) $(CC_FLAGS) $< 

