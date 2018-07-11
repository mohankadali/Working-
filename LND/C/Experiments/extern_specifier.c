#include<stdio.h>
extern int extern_var;
void print(void)
{
	printf("extern value is %d\n",extern_var);
}
