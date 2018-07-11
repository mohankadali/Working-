CC=gcc #Compiler to use
OPTIONS = -O2 -g -Wall
INCLUDES =-I .
OBJS = *.o
.PHONY:all clean
all: $(OBJS)
		@echo "Building..."
		$(CC) $(OPTIONS) $(INCLUDES) $(OBJS) -o commnd 
%.o:%.c
		$(CC) $(OPTIONS) $(INCLUDES) -c $*.c
list:
		@echo $(shell ls)
clean:
		@echo "Cleaning up.."
		-rm -rf *.o
		-rm strings
