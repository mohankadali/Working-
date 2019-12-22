#include<stdio.h> 
static int x=1;
const int y=2;
main()
{
    static int i;
    auto int j;
    char k;
    printf("x=%p y=%p i=%p j=%p k=%p\n",&x,&y,&i,&j,&k);
    x=3;
    i=4;
    j=5;
    k=6;
}
