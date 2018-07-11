#include<stdio.h>
const int g_var=10;
int main(void)
{
	//const auto ac_var=20;
	auto int a_var=g_var;
	printf("in main\n");
//	g_var=20;

	printf("a_var  value is %d\n",a_var);
	printf("a_var address is %p",&a_var);
	printf("g_var address is %p",&g_var);
	return 0;
}
