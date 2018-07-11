#include	<stdio.h>
/* #pragma pack(2) */
#pragma pack(push, 2)
struct value
    {
	int bit5;
        char bit1;
	short int bit2;
        char bit3;
    };
#pragma pack(pop)
struct value1
    {
        char bit1;
	int bit2;
        char bit3;
        char bit4;
    };
int main()
{
    struct value bit;
    struct value1 bit1;
    int *a = 1;
    a++;
    printf("%d %d %p\n", sizeof(bit), sizeof(bit1), a);
    return 0;
}
