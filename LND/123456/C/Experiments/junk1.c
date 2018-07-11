#include<stdio.h> 
  //char a[]="global edge";
 // char *c;
main()
{ 
//void *v;
  //  printf("%p ",v);
  //  printf("%d ",*v);
  char a[]="global edge";
  char *c=&a[0];
printf("%p   \n",c);
printf("%s  \n",c);
c=a;
printf("%p  \n",c);
printf("%s  \n",c);

}
