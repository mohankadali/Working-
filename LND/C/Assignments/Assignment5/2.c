#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "header.h"
int search_str()
{
    int c=0,x=0;
    char *a;
    FILE *fptr;
    fptr = fopen("raju.txt","r");
    while(fgetc(fptr)!=EOF){
        c++;
    }
    rewind(fptr);
    a=malloc(c+1);
    while(fgets(a,c,fptr))
    {
        ++x;
        if(strstr(a,"and"))
        {
            printf("%d %s\n",x,a);
        }
    }

    fclose(fptr);
    return 0;
}
