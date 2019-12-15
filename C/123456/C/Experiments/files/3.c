#include<stdio.h>

int main()
{
    FILE *fp;
    unsigned char ch; //infinity loop 
    char ch;
    fp=fopen(__FILE__, "r");
    
    while((ch=getc(fp)) != EOF)
        printf("%c", ch);

    fclose(fp);
    printf("\n", ch);
    return 0;
}
