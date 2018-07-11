CC = gcc #compiler to use
OPTION = -o2 -g -Wall
INCLUDES = -I .
OBJS =  make.c add.c 
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


