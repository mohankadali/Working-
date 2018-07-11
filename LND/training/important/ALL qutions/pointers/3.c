#include <stdio.h>
int main()
{
        int a[]={1,2,3,4,5} ; 
        int *ptr , **ptr1 ;        
        ptr = &a ;
        ptr1 = & ptr ;

        printf("%d\n",a[2]);
        printf("%d\n",ptr[2]);
        printf("%d\n",**ptr1 + 2);


}
