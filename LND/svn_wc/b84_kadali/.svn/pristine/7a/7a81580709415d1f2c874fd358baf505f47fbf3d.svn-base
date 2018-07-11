
obj-m:=ps_mod.o my_open.o my_ps.o my_release.o
 cc = gcc # compilar to use 
 OPTIONS =-O2 -g -Wall
 INCLUDES = -I. -Wno-unused-result
 Assignment5 =  main_Ass5.c
KDIR:=/lib/modules/$(shell uname -r)/build 
PWD:=$(shell pwd)
LINK:=/lib/modules/$(shell uname -r)
.PHONY :all clean
all :
	$(MAKE) -C $(KDIR) M=$(PWD) modules
	$(MAKE) -C $(KDIR) M=$(PWD) modules_install
link : 
	 ln -s $(PWD)/*.ko ${LINK} 
%.o : %.c
	$(cc) $(OPTIONS) $(INCLUDES) -c $*.c
list:
	@echo $(shell ls)
Assignment5 :
	 $(cc) $(OPTIONS) $(INCLUDES) $(Assignment5) -o Assignment5.bin
clean: 
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f module.symvers app_kmod
	@rm -f $(LINK)/*.ko
	@echo "cleaning ... "
	-rm -rf *.o
	-rm *.bin                                                                                    

