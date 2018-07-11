.PHONY: clean
ad.i:ad.c
		gcc -E ad.c > ad.i
ad.s:ad.i
		gcc -S ad.i > ad.s
ad.o:ad.s
		gcc -C ad.s > ad.o
ad:ad.o
		gcc -o ad.o > ad

clean:
		rm ad.i
		rm ad.s
		rm ad.o
		rm ad
