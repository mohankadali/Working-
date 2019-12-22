#include <stdio.h>

#if 0
int main()
{
int *p = NULL;
printf("before size %p\n",p);
free(p);
p = (int *)malloc(100);
printf("after size %p\n",p);
free(p);
printf("after size %p\n",p);
return 0;
}
#endif
#if 0
int main(void)
{
	char *p = NULL;

	while(1)
	{
		p = (char*) malloc(100); // if we run this program we need to restart the pc.
	}
	return 0;
}
#endif
#if 0 
int main(void)
{
        char *fun[] = {"aello","ab", "bye"};
        //printf("%d\n",sizeof(fun[0])) ;
        printf("%d\n",fun [0][0]);
        int i;
        for (i =0; fun [1][i]; i++);
        printf("%d\n", i);
        /*  int i;
            char *p = malloc(100);
            char *q;
            printf("%p\n",p);
            for(i=0;i<50;i++)
            {
            p[i] = 'A';
            }
            q = realloc(p,50);
            for(i=0;i<50;i++)
            {
            printf("%c\n",q[i]);
            }
         */
        //   printf("%d\n",sizeof(p));
        return 0;
}
#endif
#if 0 
int main(void)
{
    int x=10;
    printf("%p\n",&x);
    free((int*)&x);
    printf("%d\n",x);
    return 0;
}
#endif
#if 0 
int main(void)
{
    int *p  ;
    p = (char*)malloc(10);
//    strcpy((char *)p,"hello");
//    printf("%s\n",p);
    *p = 65;
    *p+1 = "S";
    printf("%s\n",p);
    return 0;
}
#endif
#if 0
int main()
{
	/*
	   int x;
	   printf("%d\n",x); // it will print null because x default value is null otherwise will get runtime error.
	 */
	/*
	   int p = malloc(10);
	   strcpy ((char*)p,"hi");
	   printf("%s\n",p);
	 */
	/*
	   int *p = malloc(10);
	 *p = 'A';
	 printf("%c\n",*p);
	 */
	/*
	   int *p = malloc(10);
	//p = 'A'; // seg fault
	 *p = 'A';
	 printf("%s\n",p);
	 */
	return 0;
}
#endif
