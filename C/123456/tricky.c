#include<stdio.h>
#if 1
int fun() // compile with gcc -nostartfiles file_name.c
{
printf("hi\n");
exit(0);
return 0;
}
#endif
#if 0
int main()
{
        int a[3];
        int i;
        for(i=0;i<10;i++){
                a[i] = i;
        }
        for(i=0;i<10;i++)
                printf("%d\n",a[i]);
}
#endif
#if 0
int main()
{
        unsigned int a = 6;
        int b = -20;
        (a+b) > 6 ? printf(">6 \n") : printf("<6 \n") ;
        return 0;
}
#endif
#if 0
void main()
{
	int  x = 0;
	if (x == 0)
		//  return 0 ;
		printf("hello");
}

#endif
#if 0
int main(void)
{
  int a=1;
  while(a = 3,printf("%d\n",a),a = 100,a++)
  {
    printf("%d\n",a);
  }
  return 0;
}
#endif
#if 0 
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
#endif
#if 0 
int main(void)
{
    int a =10;
    float j = 10.99;
    int div = a%j; // we should not use mod operator for float 
    printf("%d\n",div);
}

#endif
#if 0 
void fun(int a,int *j)
{

	a = a*a;
	*j = *j * *j;
}
int main(void)
{
	int i=10,j =20;
	fun(i,&j);
	printf("%d  %d  \n",i,j);
	return 0;
}
#endif
#if 0
printf("hello");
int main()
{
	return 0;
}
#endif

#if 0
//int var =10;
int main()
{

	int var = var;

	printf("%p\n",&var);
	printf("%p\n",var);

	return 0;
}
#endif
#if 0 
main()
{

    fun(9,2,3,4,5,6); // no syntax error for arguments 
}

fun(int q,int b) // will fetch only q,b parameters 
{
    printf("%d %d\n",q,b);
    return 0;
}
#endif

#if 0 
int main(void)
{

	int *p = (int*)&main;
	printf("%p\n",p);
	printf("%d\n",*p); // *p contains the value in side the main address 
	printf("addr of &main = %p\n",&main);
	printf("addr of main = %p\n",main);
	return 0;
}
#endif




















