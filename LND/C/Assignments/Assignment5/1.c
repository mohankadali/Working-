#include <stdio.h>
#include "header.h"
int up_to_low()
{
    int ch;
    FILE *fptr;
    FILE *ptr;
    fptr = fopen("raju.txt","r");
    ptr = fopen("raju.txt","r+");
//  ptr=fptr;
    while((ch=fgetc(fptr))!=EOF)
    {
        if(ch>='A'&& ch<='Z')
            ch=ch+32;
        //      putchar(ch);
        fputc(ch,ptr);

    }

    fclose(fptr);

    return 0;
}
