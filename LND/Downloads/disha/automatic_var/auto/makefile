.PHONY:clean

all:main.o add.o sub.o
	gcc -o $@ $^

o: *.c
	gcc -c $<   

clean:
	rm *.o
	rm all



