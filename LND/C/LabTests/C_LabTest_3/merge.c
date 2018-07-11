#include <stdio.h>

int main (void)
{
	FILE *fp1, *fp2, *fp3;
	char ch1, ch2;	

	fp1 = fopen ("first.txt", "r");		/*opening first in read mode */
	fp2 = fopen ("second.txt", "r");	/*opening second in read mode*/
	fp3 = fopen ("merge.txt", "w+");	/*opening merge in write plus mode*/

	if (fp1 == NULL)					/*checking the file is opening or not*/	
		printf ("can't open file1\n");
	
	if (fp2 == NULL)
		printf ("can't open file2\n");
	
	if (fp3 == NULL)
		printf("can't open file3\n");

	while ((fgetc(fp1) != EOF) && (fgetc(fp2) != EOF)) {`
		while ((ch1 = fgetc(fp1)) != '\n')
			fputc (ch1, fp3);
			fputc ('\n', fp3);
		
		while ((ch2 = fgetc(fp2)) != '\n')
			fputc (ch2, fp3);
			fputc ('\n', fp3);
	}
fclose (fp1);
fclose (fp2);
fclose (fp3);
}
