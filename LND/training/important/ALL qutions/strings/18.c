#include <stdio.h>
#include <string.h>
int main ( )
{
        char str[]="Hello\0world";
        printf("%d %d", sizeof(str), strlen(str));
        return 0;
}
