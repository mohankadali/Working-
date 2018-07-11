#include<stdio.h>
int main(void)
{
	char arr[]="globaledge";
	char *char_ptr;
	char_ptr=arr;
	printf("%s\n",char_ptr);
	char_ptr++;
	printf("%s\n",char_ptr);
	char_ptr=char_ptr+4;
	printf("%s\n",char_ptr);
	*char_ptr=0;
	printf("%s\n",char_ptr);
	char_ptr=0;
	printf("%s\n",char_ptr);
}
