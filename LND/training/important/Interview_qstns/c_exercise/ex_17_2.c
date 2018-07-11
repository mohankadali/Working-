#include <stdio.h>
struct aaa {
	char a:6;
	short int b:12;
	int c:5;
}tmp;

int main()
{
	printf("%d \n", sizeof(tmp));
}
