#include<stdio.h>
int main() 
{ 
    char *m[]={"jan","feb","mar"}; 
    char d[][10]={"sun","mon","tue"}; 

    printf("%s\t",m[0]);
    printf("%s\n",d[0]);
    printf("%s\n",m[0]++);
    printf("%c\n",d[0][0]); 
    return 0;
}
