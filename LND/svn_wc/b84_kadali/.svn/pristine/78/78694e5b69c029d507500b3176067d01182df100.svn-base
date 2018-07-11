#building kernel module 

cc = gcc # compilar to use 
OPTIONS = -g -Wall 
INCLUDES = -I ./   
Assignment1 =  main_Ass1.c
Assignment2 =  main_Ass2.c process_create_process.c process_create_thread.c thread_create_process.c thread_create_thread.c
Assignment3 =  main_Ass3.c local_data_pthread.c  global_data_pthread.c open_file_by_thread.c
Assignment4 =  main_Ass4.c handle_alarm.c
Assignment5 =  main_Ass5.c handle_thread_alarm.c
Assignment6 =  main_Ass6.c mutex_handle_thread_alarm.c
.PHONY :all clean
Assignment1 :
	 $(cc) $(OPTIONS) $(INCLUDES) $(Assignment1) -o Assignment1.bin -pthread
Assignment2 :
	 $(cc) $(OPTIONS) $(INCLUDES) $(Assignment2) -o Assignment2.bin -pthread
Assignment3 :
	 $(cc) $(OPTIONS) $(INCLUDES) $(Assignment3) -o Assignment3.bin -pthread
Assignment4 :
	 $(cc) $(OPTIONS) $(INCLUDES) $(Assignment4) -o Assignment4.bin -pthread
Assignment5 :
	 $(cc) $(OPTIONS) $(INCLUDES) $(Assignment5) -o Assignment5.bin -pthread
Assignment6 :
	 $(cc) $(OPTIONS) $(INCLUDES) $(Assignment6) -o Assignment6.bin -pthread
%.o : %.c
	$(cc) $(OPTIONS) $(INCLUDES) -c $*.c
list:
	@echo $(shell ls)

clean: 
	@echo "cleaning ... "
	-rm -rf *.o
	-rm *.bin                                                                                    
