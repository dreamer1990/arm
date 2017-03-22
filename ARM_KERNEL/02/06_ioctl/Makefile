
obj-m	+= test.o

#KERNEL_SRC = /lib/modules/`uname -r`/build/
KERNEL_SRC = /share/data/linux-3.5-qt

all:
	make -C $(KERNEL_SRC) M=`pwd` modules

clean:
	make -C $(KERNEL_SRC) M=`pwd` clean
	
install:
	make -C $(KERNEL_SRC) M=`pwd` modules_install




