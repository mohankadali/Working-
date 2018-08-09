#include <stdio.h>

int main()
{

        char a[] = "hi)he)llo)bye)";
        char*addr = strtok(a,")");

        printf("%s ",a);
        return 0;
}
