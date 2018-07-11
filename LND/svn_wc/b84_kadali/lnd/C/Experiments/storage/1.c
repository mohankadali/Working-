#include<stdio.h> 
static int s;
void fun();
extern int x;
main()
{
    extern int z;
    auto int i;
    register a=1;
    for(i=0;i<10000;i++)
    {
        a++;
    }
    {
        int b=a;
        printf("local value of a=%d\n",b);
    }
    printf("register value=%d\n",a);
    fun();
    fun();
    printf(" extern value=%d\n",x);
    printf(" global static value=%d\n",s);
    printf("another extern value=%d\n",z);
}
void fun()
{
    static int b; 
    printf("static value=%d\n",b++);
}
int x=90;
