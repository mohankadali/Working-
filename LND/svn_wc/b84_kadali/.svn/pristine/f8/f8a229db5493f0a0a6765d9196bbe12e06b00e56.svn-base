#include <stdio.h>
question3(){
    int ch,c=0;
    FILE *fptr;
    FILE *ptr;
    fptr = fopen("1","r");
    ptr = fopen("2","w");
    while((ch=fgetc(fptr))!=EOF){
        if(ch=='/'){
            ch=fgetc(fptr);
            if(ch=='/'){   
                while(ch!='\n'){
                    ch=fgetc(fptr);
                }
            }
            else if(ch=='*'){
                while(ch!='/')
                {
                    if(ch=='\n')
                    {
                        putc(ch,ptr);
                    }
                    ch=fgetc(fptr);
                }
                ch=fgetc(fptr);
            }
        }
        putc(ch,ptr);
    }
    fclose(fptr);
    fclose(ptr);
}
