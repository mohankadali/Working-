#include <stdio.h>
void q3(void)
{
    union tag{
        int a;
        char b; 
    }S={.a=258};
    int i;
    if(S.b==2)
    {
        printf("  little  endian\n");
        for(i=31;i>=0;i--)
        {
            printf("%d",(S.b)>>i&1);
            if(i%8==0)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
