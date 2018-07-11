#include <stdio.h>
#include "header.h"
int rem_cmnt()
{
    int ch;
    FILE *fptr;
    FILE *ptr;
    fptr = fopen("raju.txt","r");
    ptr = fopen("raju1.txt","w");
    while((ch=fgetc(fptr))!=EOF)    
    {
        if(ch=='/')
        {
            ch=fgetc(fptr);
            if(ch=='/')
            {   
                while(ch!='\n')
                {
                    ch=fgetc(fptr);
                }
//                putc(ch,ptr);
            }
            else if(ch=='*')
            {


                while(ch!='/')
                {
                    ch=fgetc(fptr);
                }
            ch=fgetc(fptr);
            }
        }
        putc(ch,ptr);
    }
    fclose(fptr);
    fclose(ptr);
return 0;
}
