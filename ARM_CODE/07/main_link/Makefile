
CROSS_COMPILE = arm-linux-
CC = $(CROSS_COMPILE)gcc
CC_FLAGS = -c -I ./include
LD = $(CROSS_COMPILE)ld
#LD_FLAGS = -Ttext=0x50000000 -Tdata=0x50000300 
LD_FLAGS = -T start.lds
OBJDUMP = $(CROSS_COMPILE)objdump
OBJDUMP_FLAGS = -D
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJCOPY_FLAGS = -O binary

TAG = start
OBJS = start.o
LIBS = lib.o main.o led.o buzzer.o key.o

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
