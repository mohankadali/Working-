CC = gcc #compiler to use
OPTION = -o2 -g -Wall
INCLUDES = -I .
OBJS =  main.c 1.c 2.c 3.c 4.c 5.c 6.c
.PHONY: all clean

all: $(OBJS)
		@echo "building.."
				$(CC) $(OPTIONS) $(INCLUDES) $(OBJS) -o final
%.o:%.c 
				$(CC) $(OPTION) $(INCLUDES) -c $*.c
list:
		@echo $(shell ls)
clean:
		@echo "cleaning up.."
		-rm -rf *.o
		-rm final


