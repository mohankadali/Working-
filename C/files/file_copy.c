//**** Exercise  1 - 12 ****//

#include<stdio.h>

int main() {
    int c;
    c = getchar();
    while (c != EOF) 
    {
        if (c == ' ') {
            putchar('\n');
        }
        else 
        {
            putchar(c);
        }
        c = getchar();
    }
return 0;
}
