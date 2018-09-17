#include <stdio.h>
int main()
{
        int a=10,b=5,c;

        while(b)
        {
                c= c+((b&1)?a:0);
                a= a<<1;
                b= b>>1; 
        }
        printf("%d\n",c);

        return 0;
}
