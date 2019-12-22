#include<stdio.h>
union ss{
//	int a:12;
	int a:12;
	char b:7;
}aa;
void dectobin(int dec )
{
        int i;
        for ( i = 31 ; i >= 0 ; i-- ) {
                if ( ( i + 1 ) % 8 == 0 )
                        printf( " " );
                dec & (1<<i) ? printf("\033[31m1\033[m"):printf("\033[35m0\033[m");
        }
}
int main()
{
	aa.b = 23;
	printf("%d",aa.a);
	printf("\nsize = %d\n",sizeof(aa));
	dectobin(aa.a);
	printf("\n");
	return 0;
}
