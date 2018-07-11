#include<stdio.h> 
void fun(int p[][3])
{
    printf("%d\n",sizeof(p));
    printf("%d\n",*(*p+0)+1);


}
int main(void)
{
int a[2][3];
    fun(a);
    return 0;
}
