#include	<stdio.h>
int main()
{
    struct value
    {
        char ch;
	short int sh;
	char ch1;
    };
    struct value bit;
    printf("%d\n", sizeof(bit));
    return 0;
}
