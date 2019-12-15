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

