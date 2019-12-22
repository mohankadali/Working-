#include<stdio.h>
struct A
{
	int ary[2];
};
struct B
{
	struct A ary[2];
};
struct C
{
	struct B ary[2];
}D[2];
int main()
{
	printf("\n%d\n",(int)&(D[1].ary[0].ary[1].ary[0])-(int)D);
}
