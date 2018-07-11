CC=gcc #Compiler to use
OPTIONS = -O2 -g -Wall
INCLUDES =-I .
OBJS = main.o add.o
.PHONY:all clean
all: $(OBJS)
		@echo "Building..."
		$(CC) $(OPTIONS) $(INCLUDES) $(OBJS) -o add
%.o:%.c
		$(CC) $(OPTIONS) $(INCLUDES) -c $*.c
list:
		@echo $(shell ls)
clean:
		@echo "Cleaning up.."
		-rm -rf *.o
		-rm add
