.PHONY:clean
app:main.o add.o sub.o
	gcc -o clean main.o add.o sub.o

%.o:%.c
	gcc -c main.c add.c sub.c   


#.PHONY:clean
clean:
	rm *.o
	rm clean



