#include<stdio.h> 
int main(void)
{
    int  *p  ;
p = malloc(10);

    strcpy(p,"hello");

    printf("%s\n",p);
//    *p = 8;
    *(p+1) = 'S';
    printf("%s\n",p);
    return 0;
}
