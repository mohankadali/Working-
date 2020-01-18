#include <stdio.h>
int main()
{

        FILE *fp;
        char ch;
        fp =fopen(__FILE__,"r");
        while((ch=getc(fp))!=EOF)
                putchar(ch);
        return 0;
}
