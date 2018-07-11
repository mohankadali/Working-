#include <stdio.h>
#include <string.h>
void printSubStr( char* str, int low, int high )
{
	int i;
	for( i = low; i <= high; ++i )
		printf("%c", str[i]);
}

int longestPalSubstr( char *str )
{
	int n = strlen( str ); // get length of input string

	int table[n][n];
	memset(table, 0, sizeof(table));

	int maxLength = 1;
	int i;
	for (i = 0; i < n; ++i)
		table[i][i] = 1;

	int start = 0;
	for (i = 0; i < n-1; ++i)
	{
		if (str[i] == str[i+1])
		{
			table[i][i+1] = 1;
			start = i;
			maxLength = 2;
		}
	}
	int k;
	for (k = 3; k <= n; ++k)
	{
		for (i = 0; i < n-k+1 ; ++i)
		{
			int j = i + k - 1;

			if (table[i+1][j-1] && str[i] == str[j])
			{
				table[i][j] = 1;

				if (k > maxLength)
				{
					start = i;
					maxLength = k;
				}
			}
		}
	}

	printf("Longest palindrome substring is: ");
	printSubStr( str, start, start + maxLength - 1 );

	return maxLength; // return length of LPS
}

int main()
{
	char str[] = "BAMALAYALAMLIRILMADAMHAAH";
	printf("nLength is: %dn", longestPalSubstr( str ) );
	return 0;
}

