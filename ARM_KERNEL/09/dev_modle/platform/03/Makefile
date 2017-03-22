
obj-m	+= dev.o
obj-m 	+= dri.o

#KERNEL_SRC = /lib/modules/`uname -r`/build/
KERNEL_SRC = /share/data/linux-3.5-qt
ROOTFS = /nfsroot

all:
	make -C $(KERNEL_SRC) M=`pwd` modules

clean:
	make -C $(KERNEL_SRC) M=`pwd` clean
	
install:
	make -C $(KERNEL_SRC) M=`pwd` INSTALL_MOD_PATH=$(ROOTFS) modules_install




