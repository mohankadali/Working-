#include<stdio.h> 
#include<string.h>

int main(void)
{
    char p[] = "hello world";
 
    char b[10],c[10];

    int i,j;
    for(i= 0;p[i];i++);
    i=i-1;
    for(j=0;i>j;j++,i--)
    {
        p[i]^=p[j]^=p[i]^=p[j];
        
    }
    fwrite( p, 15, 1, stdout   );
    printf("%s\n",p);



}
