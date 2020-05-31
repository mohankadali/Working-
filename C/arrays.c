#include <stdio.h>
#if 1
int main()
{
typedef int (*INTARRAY)[10];
typedef int (INTARR)[10];

INTARRAY a;
INTARR  b = {1,2,3,4,5};

a = &b;
printf("%d \n",sizeof (a));

b[5] = 6;
printf("%d \n", *(b + 5));
printf("%d \n", **(a + 5));
return 0;
}
#endif

#if 0
struct s
{
	int  a ; 
	//int arr[] ; 
	int b ; 
	int arr[] ; // flexible error should be at end of structure elements 
}ok ; 

int main () 
{
	printf ( "%d"  , sizeof (ok ) ); 
	return 0 ;
}
#endif
#if 0
int main()
{
        int a[][3] = {1, 2, 3, 4, 5, 6};
        int *ptr;
        ptr = a + 1;
        printf("\na = %u ptr = %u\n", a, ptr);
        ptr = ptr + 1;
        printf("\na = %u ptr = %u\n", a, ptr);
        ptr = a[0] + 1;
        printf("\na[0] = %u ptr(0) = %u\n", a[0], ptr);
        ptr = a[1] + 1;
        printf("\na[1] = %u ptr(1) = %u\n", a[1], ptr);
        ptr = &a[0] + 1;
        printf("\na[0] = %u &ptr(0) = %u\n", &a[0], ptr);
        ptr = &a[1] + 1;
        printf("\na[1] = %u &ptr(1) = %u\n", &a[1], ptr);
}
#endif
#if 0
void foo(int[3][3]);
int main(void)
{
        int a[][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
        // int a[3];
        printf("%p\n", a);
        printf("%p\n", a[0]);
        printf("%p\n", &a[1][0] );
        foo(a);
         printf("%d %d\n", a[1][1], a[2][1]);
        return 0;
}
//void foo(int b[3][3])
void foo(int (*b)[3])
{
        ++b;
        printf("%p\n", b );
        b[1][1] = 9;
}
#endif
#if 0
int main()
{
	int a[500]={[99] = 1223};
	char *c = (char*) a;
	printf("%d\n",c[99]); //output?
	return 0;
}
#endif
#if 0
nt main()
{
        int a[] = {1,2};
        int *p = malloc(sizeof(int));
        p[1] = 3;
        p = a;
        a = p; //its an error.
}
#endif
#if 0
#include<stdio.h>
int main(void)
{
//int a[10];
//a = "akshdk";
//    printf("");
void* a;
return 0;
}
#endif
#if 0
#include<stdio.h> 
int main() 
{ 
        static a[3]={1}; 
        int b[3]={1}; 
        printf("%d %d",a[0],b[0]); 
} 
#endif
#if 0
#include<stdio.h> 
int main() 
{
int a[10]= {1,2,3,34,4};
int b[10]= {11,22,33,44};
int *p = a;
int *q = b;
 p = q;
printf("%d\n",p[2]);
}
#endif
#if 0
#include<stdio.h> 
int main() 
{
        int a[]={4}; 
        int b[] = { 1, 2, 3, 4} ;
        printf("%d %d ", sizeof(a), sizeof(b)); 
}
#endif
#if 0
#include<stdio.h> 
int main() 
{
        int a[] = { 1, 2, 3, 4}; 
        int *p = (a + 2) ; 
        printf ("ans = %d  %d\n" , *(a + 1),  *(p - 1) ); 
}
#endif
#if 0
void size(int arr[10]) // parameter should be a pointer not array 
{
        printf("in size %d\t", sizeof(arr));

}
int main()
{
        int arr[10];
    //    void *arr; 
        size(arr);
        printf("in main %d\n", sizeof(arr));
        return 0;
}
#endif
#if 0
int main(void)
{
    int a[2]; a[1] = 3; a[0] = 10;
    printf("a[1] = %d\n",a[1]);
    printf("0[a] = %d\n",0[a]);
    return 0;
}
#endif
#if 0
int main()
{
    char *m[]={"jan","feb","mar"};
    char d[][10]={"sun","mon","tue"};

    printf("%s\n",m[0]);
    printf("%s\n",d[0]);
    printf("%s\n",m[0]++);
    printf("%c\n",d[0][0]);
    return 0;
}
#endif
#if 0
int main ()
{
    int a[] = { 0x001, 0x010, 0x100, 0x1000 };
    int i;
    for ( i = 0 ; i < 4 ; i++)
        printf("%d\t", a[i]);
    return 0;
}
#endif
#if 0
int main()
{
int a[0];
printf("%d\n",sizeof(a));
}
#endif
#if 0
int main()
{
    int a[0];

    printf("%d\n",sizeof(a));
    printf("%p\n",&a);
    printf("%p\n",a);
    return 0;
}
#endif
#if 0 
void fun(char *arr)
{
    int i;
    unsigned int n = strlen(arr);
    printf("n = %d\n", n);
    for (i=0; i<n; i++)
        printf("%c", arr[i]);
}

int main()
{
    char arr[] = {'m', 'o', 'h', 'a', 'n', 'k', 'r', 'i', 's', 'h', 'n','a'};
    fun(arr);
    return 0;
}
#endif

#if 0
void size(int arr[230])
{
	printf("in size %d\n", sizeof(arr));

}
int main(int b[10], char c[])

{
	;
	size(b);
	printf("in main %d\n", sizeof(b));
	printf("in main %d\n", sizeof(c));
	return 0;
}
#endif
