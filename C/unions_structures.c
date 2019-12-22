#include<stdio.h> 
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
struct st {
int b;
}*p;

int main()
{
printf("%d\n",sizeof(p));
printf("%d\n",sizeof(*p));
}
#endif
#if 0
struct st{
        int i:8;
        int j:6;
        char ch;
}pq;
void func(void *ptr)
{
        int i;
        char *r = (char *)ptr;
        printf("%d\n", *(r+1));
        //    printf("%p\n", (r+1));
}
int main()
{
        struct st pq = {1,2,3};
        func(&pq);
        return 0;
}
#endif
#if 0
int main()
{
        struct value
        {
                char ch;
                short int sh;
                char ch1;
        };
        struct value bit;
        printf("%d\n", sizeof(bit));
        return 0;
}
#endif
#if 0
int main(void)
{
   struct node
   {
      int a;
      int b;
      int c;
   };
   struct node s = { 3, 5, 6 };
   struct node *pt = &s;
   printf("%d\n", *(int*)pt);
   return 0;
}
#endif
#if 0
char * func(char *s)
{
        char str[] = "Edge";
        s = str;
        printf("%s\n", s);
        return s;
}
int main()
{
        char s[] ="Global";
        printf("%s\n", s);
        char* p = func(s);
        printf("%s\n", p); //it will not print anything what is the reason?
        return 0;
}

#endif
#if 0
struct a {
        int b;
        int c;
        int d;
} i={7,2,3};
int main(){
        struct a *p=&i;
        printf("%d\n",*p);
        printf("%d\n", (*p).c);
        printf("%d\n", p->d);
        return 0;
}
#endif
#if 0
struct marks{
            int p:3;
            int c:3;
            int m:2;
};
 void main(){
   struct marks s={2,-6,5};
   printf("%d %d %d",s.p,s.c,s.m);
}
#endif
#if 0 
struct header {
        char src[6];
        char dest[6];
        char recv[6];
};
void print_header(struct header *ptr)
{
        /* printf("%d", ((struct header *)ptr)->src[4]); */
        printf("%d", ptr->src[3]);
}
int main()
{
        struct header dev_a, dev_b = {0};
        int i;
        for (i = 0;i < 6;i++) {
                dev_a.src[i] = dev_a.dest[i] = dev_a.recv[i] = i;
        }
        for (i = 0;i < 6;i++) {
//      printf("%d %d %d ",dev_a.src[i],dev_a.dest[i],dev_a.recv[i]);
        }
        print_header(&dev_a);
        return 0;
}
#endif
#if 0
struct c{
        int a;
        int b;
        struct {
                char d;
        };
};
int main()
{
        printf("%x\n",10);
        printf("%x\n",~10);
//      printf("%d\n",sizeof(struct c));
}
#endif
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
