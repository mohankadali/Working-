#include<stdio.h>
const int global;
int data;
int main()
{
	const int local;
	printf("global = %p data = %p local = %p\n\n", &global, &data, &local);
	return 0;
}

//ADDRESS will be like "global < data < local"	it may be wrong
//ANS: global = 0x804a01c data = 0x804a020 local = 0xbfce0e0c
