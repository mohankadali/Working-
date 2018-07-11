#include<stdio.h>
#include<string.h>
void *ins_str (char *, char*);
int main(void)
{
	char p[200] = {"global edge software ltd"};
	char str[] = "raju";

	ins_str (p,str);
	printf("%s\n",p);
	return 0;
}

void *ins_str (char *ptr, char *str) 
{
	int len = strlen (str);
	char *ptr2;
	int count = 0;
	int i;

	for (i=0; ptr[i];i++) {
		if (ptr[i]==' ')
			count++;
	}
	
	
	while (count--) {
		ptr2 = strchr (ptr, ' ' );
	//	printf("%c\n",ptr2);
		
		memcpy(ptr2 + len, ptr2+1, strlen(ptr));
		printf("%s\n",ptr2);
		printf("%s\n",ptr2+len);
		memcpy (ptr2, str, strlen(str));
		printf("-------------\n");

	}
return ptr;
}
