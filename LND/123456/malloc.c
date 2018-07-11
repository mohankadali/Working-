#include<stdio.h> 
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
