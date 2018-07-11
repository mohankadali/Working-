#include <stdio.h>
#if 0
int main()
{
	char *p = "0";
	char *s = "\48";

	printf("%p\n",p);
	printf("%p\n",s);
}
#endif


#if 0
int main()
{
	int a[5] = {555,444,333,222,256};
	unsigned char *p = (unsigned char *)a;

	int i = 0;
	int temp = 0;
 
 /*	while ((++i) <= 5) {
		temp = (*p++);
		temp += (*p++) << 8;
		temp += (*p++) << 16;
		temp += (*p++) << 24;
	
		printf("%d\t" ,temp);
	}*/
	printf("\n");
	printf("%x\n",p[1]);
	printf("%x\n",p[2]);
	printf("%x\n",p[3]);
	printf("%x\n",p[4]);
	printf("%x\n",p[5]);
	printf("%x\n",p[6]);
	printf("%x\n",p[7]);
	printf("%x\n",p[8]);

	return 0;
}
#endif







#if 1
const int a=9;
int *p=&a;
int main()
{
//p=main;
*p=62;
	//int n;
	//fgets(&n,25,stdin);

	printf("%d\n",a);
}
#endif
