#include <stdio.h>

int main()
{
        char x[] = "abcdefabcdefghjabcdfehjioup";
        char freq[26]={0};
        int i;

        for(i=0;x[i];i++)
        {
                freq[x[i]-'a']++; 
        }
        for(i=0;i<26;i++)
        {
                if (freq[i] != 0)
                        printf("%c %d\n",97+i,freq[i]);
        }
        int min,max;
        min = max = freq[0];
        for (i=0;i<26;i++)
        {
                if (freq[i]<min)
                        min = freq[i];
                if (freq[i]>max)
                        max = freq[i];
        }
        printf("min :%d\t max:%d\n",min,max);  
        return 0;
}
