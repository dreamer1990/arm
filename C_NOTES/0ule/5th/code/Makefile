obj-m=test.o
KERN=/usr/src/kernels/2.6.18-194.el5-PAE-i686

all:
	make -C $(KERN) M=$(PWD) modules
clean:
	make -C $(KERN) M=$(PWD) clean
	rm -rf Module*



