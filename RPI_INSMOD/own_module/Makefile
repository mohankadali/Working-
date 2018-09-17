obj-m:=own_module.o

#KDIR:=/home/kadali/mylinux

KDIR:=/home/kadali/from_backup/MORE_SIZE/CROSS_COMPILE/RPI/25th_april/linux/
PWD:=$(shell pwd)

all:
	$(MAKE) ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f Module.symvers app_kmod
