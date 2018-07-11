SRC = *.c

CC = gcc

OPTION = -Wall -Wno-unused-result

INCLUDE = -I .

.PHONY: all clean

all : $(SRC) 
	@echo "building..."
	$(CC)  $(INCLUDE) $(OPTION) $(SRC) -o DS


clean :
	@echo "cleaning up..."
	-rm -rf *.o
	-rm DS
