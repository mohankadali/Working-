#include<stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc<2) {
		printf("error");
		return;
	} else 
		printf("no of files = %d\n",(argc-1));
	return 0;
}
