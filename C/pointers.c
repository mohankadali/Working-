#include<stdio.h>
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
int main()
{
    char *p = "abcd";

    if( p ==  "abcd" )  {
     printf( "true\n " );
    }
    else {    
    printf(" false\n");
    }

    return 0;
}
#endif
#if 0
int main()
{
    char *p = "hello";
    char q[] = "hi";
    int n;
    n = q - p;
    printf("%d\n", n);
    return 0;
}
#endif
#if 0
int main(void)
{
   int a[5] = { 1, 2, 3, 4, 5 };
   int *ptr = (int*)(&a + 1);
   printf("%d %d\n", *(a + 1), *(ptr - 1));
   return 0;
}
#endif
#if 0
int main()
{
        int a[] = {0x12345678, 0x11223344, 3, 4, 5};
        char *ptr;
        ptr = (char *)a;
        printf("%x \n", ptr[0]);
        printf("%x \n", ptr[1]);
        printf("%x \n", ptr[2]);
        printf("%x \n", ptr[3]);
        ptr = ptr+4;
        printf("%x \n", ptr[0]);
        printf("%x \n", ptr[1]);
        printf("%x \n", ptr[2]);
        printf("%x \n", ptr[3]);
        ptr = ptr+4;
        printf("%x \n", ptr[0]);
        printf("%x \n", ptr[1]);
        printf("%x \n", ptr[2]);
        printf("%x \n", ptr[3]);
        return 0;
}
#endif
#if 0
int main()
{
        int a[5] = {555,444,333,222,256};
        unsigned char *p = (unsigned char *)a;

        int i = 0;
        int temp = 0;

 /*     while ((++i) <= 5) {
                temp = (*p++);
                temp += (*p++) << 8;
                temp += (*p++) << 16;
                temp += (*p++) << 24;
        
                printf("%d\t" ,temp);
        }*/
        printf("\n");
        printf("%d\n",p[1]);
        printf("%d\n",p[2]);
        printf("%d\n",p[3]);
        printf("%d\n",p[4]);
        printf("%x\n",p[5]);
        printf("%x\n",p[6]);
        printf("%x\n",p[7]);
        printf("%x\n",p[8]);

        return 0;
}
#endif
#if 0
const int a=9;
int *p=&a;
int main()
{
//p=main;   // it will give some address 
//*p=62; // seg fault
        int n;
        fgets(&n,25,stdin); // it will seg fault some times 

        printf("%d\n",n);
}
#endif
#if 0
int main()
{
        char *p = "0";
        char *s = "\48";

        printf("%s\n",p);
        printf("%d\n",*s);
}
#endif
#if 0
int main()
{
        char c = 'a';
        char *c_ptr = &c;
        printf("%d & %d",sizeof(char),sizeof c_ptr);
        return 0;
}
#endif
#if 0
int main()
{
       // char  p[] = "abc";
        char  *p = "abc";
        printf ("%c \n", *p);
//        printf ("%c \n", *p++);
        printf ("%c \n", ++*p);
        printf ("%c \n", (*p)+1);
        return 0;
}
#endif
#if 0
main()
{
        void *p;
        printf("%p\n",p);
        p = p+1;
        printf("%p\n",p);
}
#endif
#if 0
int main()
{
        unsigned char *c;
        c = 'A';
        while (c >= 0)
                printf("%d\n", (*c)++);
}

#endif
#if 0
int main(void)
{
int ********************ptr = 56;
        char *(v[]) = {"abc","efg","jkl"};
        char **p = v;
        printf("%s\n",p[0]);
        printf("%c\n",*p[0]);
        printf("%c\n",*++p[1]);
        printf("%c\n",(*++p)[1]);
        int *(c);
        return 0;
}

#endif
#if 0
int main ()
{
        int *ptr = 10;
        int x = 1;
                printf("%d  %d \n", ptr +x, x+ptr);
        return 0;
}
#endif
#if 0
int main ()
{
        int *ptr = NULL;
        ptr++;
        printf("%d \n", *ptr);
        return 0;
}

#endif
#if 0
int main()
{
        int k = 100 ;
        const int *p =&k ;
        *p = 200 ;
        printf("%d\n",k);
}
#endif
#if 0
int main()
{
        int a[]={1,2,3,4,5} ;
        int *ptr , **ptr1 ;
        ptr = &a ;
        ptr1 = & ptr ;
        printf("%d\n",a[2]);
        printf("%d\n",ptr[2]);
        printf("%d\n",**ptr1 + 2);
}
#endif
#if 0
int main( int argc , char **argv )
{
        int k ;
        for ( k = 0 ; k < argc ; k++)
                printf( "%s ", argv[k]);
}
#endif
#if 0
int main()
{
        int *p[10];
        int *(*q)[10];
//        int (*q)[10];
        printf("%lu %lu\n", sizeof(int), sizeof(int *));
        printf("%lu %lu\n", sizeof p, sizeof p[0]);
        printf("%lu %lu\n", sizeof q, sizeof *q);
        return 0;
}
#endif
#if 0
char *fun()
{
        static char arr[1024];
        return arr;
}

int main()
{
        char *str = "global edge";
        strcpy(fun(), str);
        str = fun();
        strcpy(str, "global edge");
        printf("%s", fun());
        return 0;
}
#endif
#if 0
int main()
{
        int **ptr = NULL;
        int j=0,i=0,r=2,c=3;
        ptr = (int**) malloc(r * sizeof(int));
        for(i=0;i<r;i++)
        {
                ptr[i] = (int*)malloc(c * sizeof(int));
        }
        ptr[1][1] = 10;
        for (i=0;i<r;i++)
        {
                for(j=0;j<c;j++)
                        printf("arra =  %d\n",ptr[i][j]);
        }
        return 0;
}
#endif
#if 0
int main()
{
char a[] =  "hello";
char b[10] =  {0};
//b = a; //error
printf("%s\n",b);
return 0;
}
#endif
#if 0
int main()
{
int a[5]= {1,2,3,4,5};
int *p[5];
p[1] = &a[1];
printf("%d\n",*p[1]);
return 0;
}
#endif
#if 0
int main()
{
int *a[] = {1,2,3,4,5}; // 1 to 5 are address if we dereference those we will face run time issues seg fault.
printf("%d\n",a[0][0]);
}
#endif
#if 0
int main()
{
int a[] = {1,2,3,4,5,6,7,8};
printf("%d\n",*(a+0));
int *p = a+1;
printf("%d\n",*p);
return 0;
}
#endif
#if 0
char *n;
int main()
{
char *p = "hello guru";
char s[] = "bye master";
p = &s[3];
*s = 'A';
p = p+1;
*p= 0;
*p = n;
printf("%p\n",p);
return 0;
}
#endif
#if 0
int main()
{
char *a =  "hello";
char *b;
b = a;
printf("%s\n",b);
return 0;
}
#endif
#if 0
int main()
{
        char *ptr = NULL;
        strcpy(ptr,"hi");
        printf("%s\n",ptr);
        return 0;
}
#endif
#if 0
int main()
{
int a[5]= {1,2,3,4,5};
int (*p)[5];
p = &a;
printf("%d\n",a[1]);
printf("%d\n",p[0][0]);
return 0;
}
#endif
#if 0
int main(void)
{
    char *ptr = "hello";

    printf("%p\n",ptr);
    ptr++;
    printf("%s\n",++ptr);
    return 0;
}

#endif
#if 0 
int main(void)
{
int (*a)[3]= {12,23,45,};
printf("%d\n",)
return 0;
}

#endif
#if 0
void fun(int p[][3])
{
        printf("%d\n",sizeof(p));
        printf("%d\n",*(*p+0)+1);
}
int main(void)
{
        int a[2][3] = {1};
        fun(a);
        return 0;
}

#endif
#if 0
void f(char**);
int main()
{
	char *argv[] = { "ab", "cd", "ef", "gh", "ij", "kl" };
	f(argv);
}
void f(char **p)
{
	char *t;
	t = (p += sizeof(int))[0];
	printf("%s\n", t);
}
#endif
#if 0
int main(void)
{
    char *a[4]={1000,2000,3000,4000};
    printf("%d\n",sizeof ( (*a)[1] ));
    return 0;
}
#endif
#if 0 
int main(void)
{
    int arr[] = {10, 20};
    int *p = arr;
    ++p;
    printf("p[0] = %d, arr[1] = %d, *p = %d", p[0], arr[1], *p);
    return 0;
}
#endif
#if 0
int main()
{
	int  (*ptr)[5] ;
	int a[][5]  = {1,2,3,4,5,3};
	ptr = a;
	//    printf("%p\n",ptr);
	//    printf("%p\n",a);
	printf("%p\n",a[1]);
	printf("%p\n",ptr[1]);
	//    printf("%d\n",ptr[1][0]);
	return 0;
}
#endif
#if 0 
int main(void)
{
	int (*a)[5];
	printf("%d\n", a);
//	printf("%d\n", &a);
//	(&a)++; // we should not increment array name.
	a++;// which means it increment the address which present in an array name 'a' , it have two elements so 8 bytes will increment 
	printf("%d\n", a);
//	printf("%d\n", &a);
}
#endif
#if 0
int main()
{
        int a= 10 ;
        int *p = &a;
        (*p)++;
        printf ( "%d", a) ;
}
#endif
#if 0
int main(void)
{
    char a = "sffdhnggbiraj"; // we need to use string for  pointers or arrays only 
    printf("%s\n",a);
    return 0;
}
#endif
#if 0
int b = 10;
int main()
{
	int *p;
	int b = 20;
	p = &b;
	printf("%d\n",*p);
	printf("%p\n",&p);
	printf("%p\n",p);
	printf("%p\n",&b);
}
#endif

