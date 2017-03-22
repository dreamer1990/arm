
all:
	arm-linux-gcc -c start.s
	arm-linux-gcc -c main.c
	arm-linux-gcc -c led.s
	arm-linux-gcc -c lib.s
	arm-linux-ld start.o main.o led.o lib.o -o start
	arm-linux-objdump -D start > start.dis
	arm-linux-objcopy -O binary start start.bin

clean:
	rm -rf *.o start start.bin start.dis
