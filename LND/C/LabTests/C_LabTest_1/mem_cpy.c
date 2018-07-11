#include<stdio.h>
void *mem_copy(char *dbuf, char *sbuf, int n);
int main(void)
{
	char sbuf[100], dbuf[100];
	int n;
	printf("enter a source string\n");
	scanf("%s", sbuf);
	printf("enter a dest string\n");
	scanf("%s", dbuf);
	printf("how much you want to copy\n");
	scanf("%d", &n);
	mem_copy(dbuf, sbuf, n);
	printf("%s\n", dbuf);
	return 0;
}
void* mem_copy(char *dbuff, char *sbuff, int n)
{
	while(n) {
		*dbuff++=*sbuff;
		*sbuff++;
		n--;
	}

}

