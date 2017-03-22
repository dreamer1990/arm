
# arm-linux-gcc -c  test.c -o test.o
# arm-linux-ld -Ttest.lds  test.o -o test
# arm-linux-objcopy -O binary test test.bin

#链接文件
OBJS+=test.o basedevice.o string.o  _divsi3.o _udivsi3.o  enable_mmu.o vector.o
OBJS+=irq.o  timer.o

#目标文件
TARGET=test

#链接关系
CCFLAG=-fno-builtin   
CROSS_COMPILE=arm-linux-
LINKSCRIPT=test.lds

${TARGET}.bin:${TARGET}
	${CROSS_COMPILE}objcopy  -O binary  $^  $@
	make -C  vector

${TARGET}:${OBJS}
	${CROSS_COMPILE}ld  -T ${LINKSCRIPT}  $^ -o $@ 
	#${CROSS_COMPILE}ld  -Ttext=0x40008000 $^ -o $@

%.o:%.c
	${CROSS_COMPILE}gcc -c $^ -o $@  ${CCFLAG}
%.o:%.S
	${CROSS_COMPILE}gcc -c $^ -o $@  ${CCFLAG}

clean:
	rm -rf  *.o ${TARGET}  ${TARGET}.bin
	make clean -C vector
