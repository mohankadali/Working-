#include<stdio.h>
struct M {
	int a:6;
 	int :27;
     	char c;
    	char b:4;
}s13;

int main()
{

	printf("%d\n",sizeof(s13));
	return 0;
}



