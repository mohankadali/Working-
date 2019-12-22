#include<stdio.h>
#if 0
#endif
#if 0
#endif
#if 0

#endif
#if 0
int i = 200;
int j = 300;
int main(void)
{
#if i == j  // will it perform operations ?
	printf("Hello World\n");
#endif
	return 0;
}
#endif
#if 0
int main(void)
{
        int x = 1;
        int y = 2;
        if(--x && ++y);
        printf("%d   %d\n",x,y);
        return 0;
}
#endif
#if 0
const int global;
int data;
int main()
{
        const int local;
            printf("global = %p data = %p local = %p\n\n", &global, &data, &local);
                return 0;
}
//ADDRESS will be like "global < data < local" it may be wrong
////ANS: global = 0x804a01c data = 0x804a020 local = 0xbfce0e0c
#endif
#if 0
const int b = 20;// stores in .rodata 
const int c; // stores in .bss 
int main()
{
    int *ptr;
    ptr = &c;
//    ptr = &b;
    *ptr = 10;
    printf("%d",c);
  //  printf("%d",b);
    return 0;
}
#endif
#if 0
int main()
{
        int i=543;
        printf("%d\n",printf("%d",printf("%d",i)));
        return 0;
}
#endif
#if 0
int main()
{
        int i;
        for(i = 0;i < 5;i++) {
                fprintf(stdout,"hello-out");
        //      printf("hello-out");
                sleep(1);
                fprintf(stderr,"hello-err");
        }
        return 0;
}
#endif
#if 0
int main(void)
{
   int i = 3;
   int j;
   j = sizeof(++i + ++i); // sizeof wont perform any operation inside 
   printf("i=%d j=%d\n", i, j);
   return 0;
}
#endif
#if 0
int main()
{
        int i, j;
        i = (1,2,3);
        printf("\nNumber:%d", i);
        i = 1,2,3;
        printf("\nNumber:%d\n", i);
        return EXIT_SUCCESS;
}
#endif
#if 0
int main()
{
        int x = 1, y = 0, z = 3;
        x > y ? printf("%d", z) : return 0; // we should not use return in ternery operation.
}
#endif
#if 0
int main()
{
        unsigned char ch;
        ch = 256;
        printf("%d \n", ch);
        return 0;
}
#endif
#if 0
#define MAX  220
enum x {a =90,b,c};
const int x =10;
static int y = MAX;
int main()
{
}
#endif
#if 0
void visit();
int main()
{
  int i=0;
  {                    //Opening inner block
    int a=5;  //locally declaration
XYZ:;            //Label of goto statement
    printf("%d  ",a);
    a++;
    i++;
  }                     //closing inner block.   
  visit();
  /* printf("%d",a); Variable a is not visible here but
     it is alive. */
  if(i<5)
    goto XYZ;
  return 0;
}
void visit()
{
}
#endif
#if 0
int f(int n)
{
        static int i = 1;
        if (n >= 5)
                return n;
        n = n+i;
        i++;
        return f(n);

}
#endif
#if 0
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




















