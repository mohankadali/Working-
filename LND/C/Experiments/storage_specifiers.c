#include<stdio.h>
static function();
int extern_var=5;
static int static_var=6;
int main(void)
{
	auto int auto_var=3;
	register int reg_var=5;
	printf("auto variable is %d\n",auto_var);
	printf("auto variable address is %p\n",&auto_var);
	printf("register variable is %d\n",reg_var);
	printf("register variable address is %p\n",&reg_var);
	printf("static variable is %d\n",static_var);
	printf("static variable is %d\n",static_var);
	static_var=static_var+4;
	print();
	return 0;
}
function()
{
	printf("static variable is %d\n",static_var);
}
