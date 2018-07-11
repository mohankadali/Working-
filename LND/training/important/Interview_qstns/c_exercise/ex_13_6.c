#include <stdio.h>
union float_bit {
	float f;
	int i;
}fl;

void dectobin(int dec )
{
	int i;
	for ( i = 31 ; i >= 0 ; i-- ) {
		if ( i == 30 || i == 22 )
			printf( "    " );
		dec & (1<<i) ? printf("\033[31m1\033[m"):printf("0");
	}
}

int main()
{
	scanf("%f", &fl.f);

	printf("Sign   Exp        Mantissa\n");

	dectobin(fl.i);
	printf("\n");
}
