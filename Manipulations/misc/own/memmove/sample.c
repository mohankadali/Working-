#include <stdio.h>
#include <string.h>
int main()
{
        char a[] = "hi bye tata";
        char b[] = "anill";
        printf("%s\n",a);
        memmove(a+6,a+2,9);

        memmove(a+2,b,5);

        printf("%s\n",a);

        return 0;
}
