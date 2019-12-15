#include<stdio.h> 
main()
{
    int j;
    int hex=0;
    int i;
    printf("enter binary value...\n");
    for(i=3;i>=0;i--)
    {
        scanf("%d",&j);
        hex=hex|(j<<i);
    }
printf("binary to hex= %x\n",hex);
}
