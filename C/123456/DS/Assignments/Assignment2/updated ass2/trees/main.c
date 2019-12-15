#include"header.h"

struct node
{
	int data;
	struct node *prev;
	struct node *next;
} *head;

int  main()                                             //program starts from here.....    
{
	int option, data, num;

	char ch;
	while(1) {
		printf("want to insert press ->1\n want to delete press ->2\n want to print press ->3\n want to search press ->4\n want to exit press ->5\n");
		fgets((char*)&option,3,stdin);         
		option = atoi((char*)&option);  
		switch(option)
		{   
			case 1:
				printf("enter data\n");
				fgets((char*)&data, sizeofint(int), stdin);
				data=atoi((char*)&data);
				add_ele (data);
				break;
			case 2:   
				printf("enter data to be deleted\n");
				fgets((char*)&data, sizeofint(int), stdin);
				data=atoi((char*)&data);
				del_ele (data);
				break;
			case 3:
				print();
				break;
			case 4:
				printf("enter data to be deleted\n");
				fgets((char*)&data, sizeofint(int), stdin);
				data=atoi((char*)&data);
				search(data);
			case 5:
				exit(0);
			default:printf("invalid entry\n");
				break;
		}
	}
}
