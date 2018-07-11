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

#if 1
#include<stdio.h> 
int main() 
{
        int a[] = { 1, 2, 3, 4}; 
        int *p = (a + 2) ; 
        printf ("ans = %d  %d\n" , *(a + 1),  *(p - 1) ); 
}
#endif


























