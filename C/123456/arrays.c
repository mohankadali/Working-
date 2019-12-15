#include <stdio.h>
#if 1
int main()
{
int a[0];
printf("%d\n",sizeof(a));
}
#endif
#if 0
int main()
{
    int a[0];

    printf("%d\n",sizeof(a));
    printf("%p\n",&a);
    printf("%p\n",a);
    return 0;
}
#endif
#if 0 
void fun(char *arr)
{
    int i;
    unsigned int n = strlen(arr);
    printf("n = %d\n", n);
    for (i=0; i<n; i++)
        printf("%c", arr[i]);
}

int main()
{
    char arr[] = {'m', 'o', 'h', 'a', 'n', 'k', 'r', 'i', 's', 'h', 'n','a'};
    fun(arr);
    return 0;
}
#endif

#if 0
void size(int arr[230])
{
	printf("in size %d\n", sizeof(arr));

}
int main(int b[10], char c[])

{
	;
	size(b);
	printf("in main %d\n", sizeof(b));
	printf("in main %d\n", sizeof(c));
	return 0;
}
#endif
