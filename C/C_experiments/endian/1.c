#include<stdio.h> 
main()
{
    int i=258;
    char *p=(char*)&i;
    if((*p)==2)
    {
        printf("address=%p\n",p);
        printf("little endian\n");
        p++;
        printf("incremented  address=%p\n",p);

    }
    else
    {
        printf("big endian\n");
    }
}
