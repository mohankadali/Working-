#include<stdio.h> 
#define FUN(num)  (((num&0x0f0f0f0f)<<4 ) |  ((num & 0xf0f0f0f0) >> 4))

int main(void)
{
    signed int  i = -1;
    unsigned int   j = -1;
    int p;

    printf("i = %d\n",i);
    i = i>>1;
    i = i>>1;
    printf("modified i = %d\n",i);
    for(p=31;p>=0;p--)
    {
        printf("%d",(i>>p)&1);
    }
    printf("\n");
    printf("before modifing j = %d\n",j);
    for(p=31;p>=0;p--)
    {
        printf("%d",(j>>p)&1);
    }
    printf("j = %d\n",j);
    j = j>>1;
    j = j>>1;
    printf("modified j = %d\n",j);
    for(p=31;p>=0;p--)
    {
        printf("%d",(j>>p)&1);
    }

    /*int p;
    //int num = 0xabcdefab;
    {
    printf("%x ",FUN(0xabcdefab));
    }*/
    printf("\n");
    return 0;
}
