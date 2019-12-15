#include<stdio.h>
void question1(void){
    int ch;
    int num;
    FILE *fptr;
    FILE *ptr;
    fptr = fopen("1","r");
    ptr = fopen("2","r+");
    while((ch=fgetc(fptr))!=EOF){
        if(ch>='A'&& ch<='Z')
            ch=ch+32;
        fputc(ch,ptr);
    }
    fclose(fptr);
}
