#include <stdio.h>
#if 1
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
        fwrite( p, 15, 1, stdout);
        printf("%s\n",p);
}

#endif
#if 0
char b[2] = "tata"; // will give a warning array of chars is too long 
int main()
{

char a[2] = "hello"; // will give a warning array of chars is too long 
printf("%s\n",a);
printf("%s\n",b);

return 0;
}
#endif
