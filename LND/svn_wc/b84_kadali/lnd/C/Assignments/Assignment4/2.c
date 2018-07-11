#include <stdio.h>
void q2(void)
{
    union tag{
        int a:5;
        int b:10;
        int c:5;
        int d:21;
        int e;
    }S={.e=-1};
    printf("%d\n",sizeof(S));
    int i;
    printf("%d\n",S.a);
    printf("%d\n",S.b);
    printf("%d\n",S.c);
    printf("%d\n",S.d);
    printf("%d\n",S.e);
    for(i=31;i>=0;i--)
    {
        printf("%d",(S.a)>>i&1);
        if(i%8==0)
        {
            printf(" ");
        }
    }
    printf("\n");
    for(i=31;i>=0;i--)
    {
        printf("%d",(S.b)>>i&1);
        if(i%8==0)
        {
            printf(" ");
        }
    }
    printf("\n");
    for(i=31;i>=0;i--)
    {
        printf("%d",(S.c)>>i&1);
        if(i%8==0)
        {
            printf(" ");
        }
    }
    printf("\n");
    for(i=31;i>=0;i--)
    {
        printf("%d",(S.d)>>i&1);
        if(i%8==0)
        {
            printf(" ");
        }
    }
    printf("\n");
    for(i=31;i>=0;i--)
    {
        printf("%d",(S.e)>>i&1);
        if(i%8==0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

