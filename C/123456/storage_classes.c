#include <stdio.h>
#if 1
#endif
#if 1
#endif
#if 1
#endif
#if 1
#endif
#if 1
#endif
#if 1
#endif
#if 1
#endif
#if 1
#endif
#if 1
#endif
#if 0 
void staticDemo()
{
        static int i;
        {
                static int i = 1;
                printf("%d ", i);
                i++;
        }
        printf("%d\n", i);
        i++;
}
int main()
{
        staticDemo();
        staticDemo();
}

#endif
#if 0
int * foo()
{
static  int a = 5;
        return &a;
}

int main()
{
        int* p = foo();
        printf("%d\n",*p);
        *p = 8;
        printf("%d\n",*p);
}
#endif
#if 0
int main()
{
    int x = 5;
    int const * ptr = &x;
    ++(*ptr);
    printf("%d", x);
    return 0;
}
#endif
#if 0
int main()
{
  typedef int *i;
  int j = 10;
  i a = &j;
  printf("%d", *a);
  return 0;
}

#endif
#if 0
int main()
{
	typedef static int *i; //typedef also a storage class we should not use 
	int j;
	i a = &j;
	printf("%d", *a);
	return 0;
}
#endif
#if 0
int main()
{
int *p = 90;
extern *q ;
printf("%d\n",q); // defined reference to q 
printf("%d\n",*p);//we shouldn't dereference this address directly because some other variables use same address finally we will get seg fault

return 0;
}
#endif
#if 0
int main()
{
    static int i = 5;
//    if (i--) // output 4,3,2,1,0
    if(--i)    // output 4,3,2,1	
    {
        printf("%d ", i);
        main();
    }
    return 0;
}
#endif
#if 0
int a;
int main()
{
extern int a;
printf("%d\n",a);
}
a = 90; // which means two times we are defining a value because already we defined int a value to zero which is no use
#endif
