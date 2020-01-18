#include <stdio.h>

int main()
{
        char a[] = "abcdsweasbcdvsadfresbavdcsbqwe";

        char b[26] = {0}  ;

        int i;
        for (i=0;a[i];i++)
        {
                b[a[i]- 'a']++;
        }

        for(i=0;i<26;i++)
        {
                printf(" %d \n",b[i]);
        }
        return 0;
}
