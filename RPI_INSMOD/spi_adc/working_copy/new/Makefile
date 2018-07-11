
#obj-m:=spi_driver.o

#KDIR:=/lib/modules/$(shell uname -r)/build
#PWD:=$(shell pwd)

#all:
#	$(MAKE) -C $(KDIR) M=$(PWD) modules

#clean:
#	$(MAKE) -C $(KDIR) M=$(PWD) clean
#	@rm -f Module.symvers app_kmod
#	rm app

#obj-m:=kmod1.o
obj-m:=spi_driver.o

KDIR:=/home/ravindra/linux
PWD:=$(shell pwd)

all:
	$(MAKE) ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f Module.symvers app_kmod
	rm app
