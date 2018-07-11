#include<stdio.h> 
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


}
