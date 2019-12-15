#include<stdio.h> 
#if 0
struct st{
short int c;
short int d;
short int e;
//int f;
};
int main()
{
  struct st a;
  printf("%d\n",sizeof(a));
  return 0;
}
#endif
#if 0
struct st {
  int a;
  int b;
  int c;
}*p;

int main()
{
printf("%d\n",sizeof(p));
printf("%d\n",sizeof(*p));
}
#endif
#if 0
union telephone
{
	char name[3];
	int number;
};
int main()
{
	union telephone index = {
		.number = 12345,
		.name = "Aoe"
	};
	printf("Name: %s\n", index.name);
	printf("Telephone number: %d\n", index.number);
	return 0;
}

#endif
#if 0
struct st
{
        char e;
        int s;
}A[10];

int main()
{
        /*
           close(1);
           printf("%d\n",sizeof(A));
         */
        /*
           open(1); 
           printf("%d    ",sizeof(A));
         */
        int i;
        printf("enter interger\n");
        for(i= 0; i<5;i++)
        {
                scanf("%d",&A[i].s);
        }
        for(i= 0; i<5;i++)
        {
                printf("%d\n",A[i].s);
        }
        printf("enter characters\n");
        for(i= 0; i<5;i++)
        {
                scanf("%c ",&A[i].e);
        }
        for(i= 0; i<5;i++)
        {
                printf("%c\n",A[i].e);
        }
        return 0;
}

#endif
#if 0
int main(void)
{

    union tag {
    int a;
    char ch[4];
    int b;
    };

    union tag u_tag;
    u_tag.a  = 0;
    u_tag.ch[0]  = 'c';
    u_tag.ch[1]  = 'g';

    printf("%s\n",u_tag.ch);
return 0;
}
#endif
