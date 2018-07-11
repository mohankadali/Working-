#include<stdio.h>
int str_len (char *);
int str_cmp (char *, char *);

char sbuf[100], dbuf[100];
int s_len, d_len, res;

int main (void)
{
	printf ("enter source string\n");
	fgets (sbuf, 100, stdin);
	s_len = str_len (sbuf);
	printf ("enter destination string\n");
	fgets (dbuf, 100, stdin);
	d_len = str_len (dbuf);
	if(s_len == d_len) {
		res = str_cmp (sbuf, dbuf);
		if (res == 0)
			printf ("equal\n");
		else
			printf ("not equal\n");
	}
	if(s_len > d_len)
		printf ("source string is greater than destionation string\n");
	if(s_len < d_len)
		printf ("source string is less than destination string\n");
	return 0;
}
