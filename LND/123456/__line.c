#include<stdio.h> 

int main()
{
    char num[3];
    printf("Current File :%s\n", __FILE__ );
    printf("Current Date :%s\n", __DATE__ );
    printf("Current Time :%s\n", __TIME__ );
    printf("Line Number :%d\n", __LINE__ );
    printf("standard conforming:%d\n", __STDC__ );
    // num = printf(NULL);
    // printf("return = %d\n",num);
    fprintf (stderr, "Internal error: " "negative string length " "%d at %s, line %d.",100, __FILE__, __LINE__);
    int x;

    x = fgets(num,6,stdin);
    printf("return = %d\n",x)  ; 
    return 0;
}
