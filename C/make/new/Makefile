cc = gcc 
VPATH : src:dst:home
vpath %.c src:dst:home
OBJ  = main1.o fun1.o fun2.o
.PHONY : clean  

target:$(OBJ)                 

	${cc} $^  -o  clean


clean : 
	rm -rf *.o siraj
