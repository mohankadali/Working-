#include <stdio.h>
union double_bit {
	double f;
	int i[2];
}fl;

void dectobin(int *dec )
{
	int i;
	for ( i = 31 ; i >= 0 ; i-- ) {
		if ( i == 30 || i == 19 )
			printf( "    " );
		dec[1] & (1<<i) ? printf("\033[31m1\033[m"):printf("0");
	}
	for ( i = 31 ; i >= 0 ; i-- ) {
		dec[0] & (1<<i) ? printf("\033[31m1\033[m"):printf("0");
	}
}

int main()
{
	scanf("%lf", &fl.f);

	printf("Sign   Exp        Mantissa\n");

	dectobin(fl.i);
	printf("\n");
}
