
#obj-m:=spi_driver.o

#KDIR:=/lib/modules/$(shell uname -r)/build
#PWD:=$(shell pwd)

#all:
#	$(MAKE) -C $(KDIR) M=$(PWD) modules

#clean:
#	$(MAKE) -C $(KDIR) M=$(PWD) clean
#	@rm -f Module.symvers app_kmod
#	rm app

#obj-m:=spi_driver.o

obj-m:=lskmod1.o
KDIR:=/home/kadali/from_backup/MORE_SIZE/CROSS_COMPILE/RPI/25th_april/linux/
PWD:=$(shell pwd)

all:
	$(MAKE) ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f Module.symvers app_kmod
#rm app











