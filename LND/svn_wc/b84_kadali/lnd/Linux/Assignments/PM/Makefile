#building kernel module 
obj-m:=vfork.o my_open.o my_vfork.o my_release.o
KDIR:=/lib/modules/$(shell uname -r)/build 
PWD:=$(shell pwd)


cc 		=  gcc # compilar to use 
OPTIONS 	=  -O2 -g -Wall
INCLUDES 	=  -I. -Wno-unused-result
Assignment1     =  main_Ass1.c local_data_fork.c  global_data_fork.c open_file_before_fork.c 
Assignment2     =  main_Ass2.c local_data_vfork.c  global_data_vfork.c open_file_before_vfork.c
Assignment3     =  main_Ass3.c
Assignment4     =  main_Ass4.c

all :
	$(MAKE) -C $(KDIR) M=$(PWD) modules
	$(MAKE) -C $(KDIR) M=$(PWD) modules_install

.PHONY :all clean
Assignment1 :
	 $(cc) $(OPTIONS) $(INCLUDES) $(Assignment1) -o Assignment1.bin
Assignment2 :
	 $(cc) $(OPTIONS) $(INCLUDES) $(Assignment2) -o Assignment2.bin
Assignment3 :
	 $(cc) $(OPTIONS) $(INCLUDES) $(Assignment3) -o Assignment3.bin
Assignment4 :
	 $(cc) $(OPTIONS) $(INCLUDES) $(Assignment4) -o Assignment4.bin

%.o : %.c
	$(cc) $(OPTIONS) $(INCLUDES) -c $*.c
list:
	@echo $(shell ls)

clean: 
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	@rm -f module.symvers app_kmod
	@rm -f $(LINK)/*.ko
	@echo "cleaning ... "
	-rm -rf *.o		
	-rm *.bin   	                                                                                 
