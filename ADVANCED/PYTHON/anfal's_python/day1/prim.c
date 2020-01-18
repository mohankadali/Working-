#include<stdio.h>
int main(void)
{
	int i, j;
	for(i = 1; i < 20; i++){
		for(j = 2;j < i; j++){
			if(i % j == 0)
				break;
		}
		if( i == j)
		printf("i = %d\n", i);
	}
	return 0;
}

