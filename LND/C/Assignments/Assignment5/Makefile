CC=gcc #Compiler to use
OPTIONS = -O2 -g -Wall -Wno-unused-result
INCLUDES =-I .
OBJS = *.o
.PHONY:all clean
all: $(OBJS)
		@echo "Building..."
		$(CC) $(OPTIONS) $(INCLUDES) $(OBJS) -o files 
%.o:%.c
		$(CC) $(OPTIONS) $(INCLUDES) -c $*.c
list:
		@echo $(shell ls)
clean:
		@echo "Cleaning up.."
		-rm -rf *.o
		-rm files
