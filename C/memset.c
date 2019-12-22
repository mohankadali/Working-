#include<stdio.h> 
int main(void)
{
char p[] = "hello";
int i;
int n = 2;
for(i = 0 ;i<n ;i++)
{
p[i] = '$';
}

//memset(p,'$',2);

printf("%s\n",p);

return 0;

}
