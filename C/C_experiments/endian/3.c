#include <stdio.h>
int main()
{
    long int bin, hex = 0, i = 1, rem;
    printf("Enter the binary number: ");
    scanf("%ld", &bin);
    while (bin != 0)
    {
        rem = bin % 10;
        hex = hex + rem * i;
        i = i * 2;
        bin = bin / 10;
    }
    printf("Equivalent hexadecimal value: %lX", hex);
    return 0;
}
