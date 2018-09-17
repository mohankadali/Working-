#include <stdio.h>
int main()
{

char ch[12] = {'a', 'b','c','d','e','f','g','h',10};
int *i;

i = (int*)ch;
	
printf("%s\n",(char*)i);
printf("%s\n",(char*)++i);
printf("%d\n",(int)*(++i));

return 0;
}
