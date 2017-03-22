
CROSS_COMPILE = arm-linux-
CC = $(CROSS_COMPILE)gcc
CC_FLAGS = -c -I ./include -O3 
LD = $(CROSS_COMPILE)ld
LD_FLAGS = 
OBJDUMP = $(CROSS_COMPILE)objdump
OBJDUMP_FLAGS = -D
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJCOPY_FLAGS = -O binary

TAG = start
OBJS = start.o
LIBS = main.o led.o buzzer.o key.o lib.o 

all: $(OBJS) $(LIBS)
	$(LD) $(LD_FLAGS) $(OBJS) $(LIBS) -o $(TAG)
	$(OBJDUMP) $(OBJDUMP_FLAGS) $(TAG) > $(TAG).dis
	$(OBJCOPY) $(OBJCOPY_FLAGS) $(TAG) $(TAG).bin

%.o:%.s
	$(CC) $(CC_FLAGS) $< 
%.o:%.S
	$(CC) $(CC_FLAGS) $< 
%.o:%.c
	$(CC) $(CC_FLAGS) $< 

clean:
	rm -rf *.o start start.bin start.dis
