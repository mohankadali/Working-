#include<stdio.h> 
char * rec (char*s, int i)
{
    static int j;
    int temp;
    if (i > j)
    {
        temp = s[i] ;
        s[i] = s[j] ;
        s[j] = temp ;
        i--,j++;
        rec(s,i);
    }
    return s ;
}
main()
{
    char p[] = "hello";
    int i = strlen(p);
    char *q =  rec(p,i-1);
    printf("%s\n",q);
}
