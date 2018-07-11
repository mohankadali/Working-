#include <stdio.h>
int main()
{
    int x = 5;
    int const * ptr = &x;
    ++(*ptr);
    printf("%d", x);
   
    return 0;
}
