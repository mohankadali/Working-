CC = gcc #Compiler to use
OPTIONS = -g -Wall -Wno-unused-result

INCLUDES = -I .

#OBJS = main.o add.o
SRC = *.c 

.PHONY: all clean

all: $(SRC)
	@echo "building.."
	$(CC) $(OPTIONS) $(INCLUDES) $(SRC) -o DS_a2 

%.o: %.c
	$(CC) $(OPTIONS) $(INCLUDES) -c $*.c

list: 
	@echo $(shell ls)

clean:
	@echo "cleaning up.."
	-rm -rf *.o
	-rm DS_a2
