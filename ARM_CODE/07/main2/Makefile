
TOPDIR = $(shell pwd)
CROSS_COMPILE = arm-linux-
export TOPDIR CROSS_COMPILE

include config.mk

TAG = start
OBJS = arch/arm/armv7/start.o
LIBS = main/libmain.o
LIBS += driver/libdriver.o
LIBS += lib/libl.o

all: DO_OBJ
	$(LD) $(LD_FLAGS) $(OBJS) $(LIBS) -o $(TAG)
	$(OBJDUMP) $(OBJDUMP_FLAGS) $(TAG) > $(TAG).dis
	$(OBJCOPY) $(OBJCOPY_FLAGS) $(TAG) $(TAG).bin

DO_OBJ:
	for dir in $(dir $(OBJS), $(LIBS)) ; do\
		make -C $$dir all; done

%.o:%.s
	$(CC) $(CC_FLAGS) $< 
%.o:%.S
	$(CC) $(CC_FLAGS) $< 
%.o:%.c
	$(CC) $(CC_FLAGS) $< 

clean:
	for dir in $(dir $(OBJS), $(LIBS)) ; do\
		make -C $$dir clean; done
	rm -rf *.o start start.bin start.dis
