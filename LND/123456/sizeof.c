#include<stdio.h> 
int main(void)
{
    char *a[4]={1000,2000,3000,4000};
    printf("%d\n",sizeof ( (*a)[1] ));
    return 0;
}
