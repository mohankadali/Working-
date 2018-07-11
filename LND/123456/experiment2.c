#include<stdio.h>
int main()
{
    FILE *fp;
    int i=0;
    fp=fopen("myfile.txt","w");
    fseek(fp,5,SEEK_SET);

    while (!  fseek(fp,-2, SEEK_CUR )  )
        putc('A' + i++ , fp);
 //       putc('A' , fp);
    return 0;
}

