#include <stdio.h>

struct Bookinfo
{
    char bname[20];
    int pages;
    int price;
};

int main()
{
    struct Bookinfo *book[10];

   int i;


    for(i=0;i<3;i++)
    {
   book[i] =  malloc( sizeof( struct  Bookinfo  ) );

   printf("base address %p\n",&book);
   printf("array address %p\n",book[i]);

       /* printf("\nEnter the Name of Book    : ");
        scanf("%s",book[i]->bname);
        printf("\nEnter the Number of Pages : ");
        scanf("%d",&book[i]->pages);
        printf("\nEnter the Price of Book   : ");
        scanf("%d",&book[i]->price);
        */
    }    

    printf("\n--------- Book Details ------------ ");

    for(i=0;i<3;i++)
    {
      /*  printf("\nName of Book    : %s",book[i]->bname);
        printf("\nNumber of Pages : %d",book[i]->pages);
        printf("\nPrice of Book   : %d",book[i]->price);
   */
        }    

    return 0;
}
