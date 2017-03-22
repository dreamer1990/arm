
all:
	arm-linux-gcc -c start.s -O3 -I .
	arm-linux-gcc -c main.c -O3 -I .
	arm-linux-gcc -c led.c -O3 -I .
	arm-linux-gcc -c buzzer.c -O3 -I .
	arm-linux-gcc -c key.c -O3 -I .
	arm-linux-gcc -c lib.c -O3 -I .
	arm-linux-ld start.o main.o led.o buzzer.o key.o lib.o -o start
	arm-linux-objdump -D start > start.dis
	arm-linux-objcopy -O binary start start.bin

clean:
	rm -rf *.o start start.bin start.dis
