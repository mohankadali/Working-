# include <stdio.h>
int main ()
{
    int a[] = { 0001, 0010, 0100, 01000 };
    int i;
    for ( i = 0 ; i < 4 ; i++)
        printf("%o\t", a[i]);
    return 0;
}
