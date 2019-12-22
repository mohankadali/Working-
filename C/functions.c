#include<stdio.h>
#if 0
void foobar1(void)
{
        printf("In foobar1\n");
}

void foobar2() // need to use void.
{
        printf("In foobar2\n");
}

int main()
{
        char ch = 'a';
        int a;
        foobar1();
        foobar2(33, ch, a);
        return 0;
}
#endif
#if 0 
//int (*fun_ptr[3])();
void fun()
{
        printf("hi i am fun...\n");
}
/*
   void mohan()
   {
   fun();
   return;
   }
   void another_fun( int (*fun[3])() )
   {
   fun();
   printf("hi  i am another funpointer...\n");

   }
 */
int main(void)
{
        int i;
        int  (*fun_ptr[3])() = {fun,fun,fun};
        for( i = 0 ; i < 3; i++) {
                fun_ptr[i]();
        }
        //another_fun( fun_ptr  );
        return 0;
}
#endif
#if 0 
void add(int a, int b)
{
    printf("Addition is %d\n", a+b);
}
void subtract(int a, int b)
{
    printf("Subtraction is %d\n", a-b);
}
void multiply(int a, int b)
{
    printf("Multiplication is %d\n", a*b);
}
int main()
{
    // fun_ptr_arr is an array of function pointers
    void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
    unsigned int ch, a = 15, b = 10;
    printf("Enter Choice: 0 for add, 1 for subtract and 2 "
            "for multiply\n");
    scanf("%d", &ch);
    if (ch > 2) return 0;
    (*fun_ptr_arr[ch])(a, b);
    return 0;
}

#endif
#if 0 
void fun(int a)
{
	printf("%d\n",a);
}
int main(void)
{
	void (*fun_ptr)() = fun ;

	(fun_ptr)(10);

	return 0;
}
#endif
#if 0
int main(void)
{

	int fun()
	{
		printf("hello..\n");
	}
	fun();
	return 0;
}
#endif

#if 0 
int main()
{
	int a = 10, b = 20;
	int fun(int c, int d)
	{
		return c+d;
	}
	printf("%d\n",fun(a,b));
	return 0;
}

#endif

