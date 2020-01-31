#include <stdio.h>
#include <stdlib.h>
typedef struct st{
	int r;
	struct st *next;
}ST;
void add_first(ST **ptr, int num)
{
	ST *temp;
	temp = malloc(sizeof(ST));
	temp -> r = num;
	temp -> next = *ptr;
	*ptr = temp;
}
void add_last(ST **ptr, int num) 
{
	ST *temp1 = *ptr;
	ST *temp = malloc(sizeof(ST));
	temp -> r = num;
	while(temp1 -> next != 0)
	{
		temp1 = temp1 -> next;
	}
	temp -> next = temp1 -> next; 
	temp1 -> next = temp;
}
void add_middle(ST **ptr,int num)
{
	ST *temp = malloc(sizeof(ST));
	ST *fast = *ptr;
	ST *slow = *ptr;
	temp -> r = num;
	while(fast -> next != 0  && fast -> next -> next != 0)
	{
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	temp -> next = slow -> next;
	slow -> next = temp;
}
void print_nth_last(ST *ptr, int n)
{
	ST *temp = ptr;
	int i, len =0;
	while(temp != 0)
	{
		temp = temp -> next;
		len++;
	}
	if(len < n)
		return ;
	printf("len :%d\n",len);
	temp = ptr;
	for(i = 0; i < len-n; i++)
	{
		temp = temp -> next;
	}
	printf("%d\n",temp -> r);
}	
void display(ST *ptr)
{
	while (ptr)
	{
		printf("%d, ", ptr->r);
		ptr = ptr -> next;  
	}
	printf("\n");
}
void reverse(ST **ptr)
{
	ST *pri =0, *cur = 0, *nex = *ptr;

	while(nex)
	{
		cur = nex;
		nex = cur -> next;
		cur-> next = pri;
		pri = cur;
	}
	*ptr = pri;
}
void delete_last(ST **ptr)
{
	ST *temp = *ptr;
	ST *temp1 = *ptr;
	while(temp1 -> next != 0)
	{
		temp = temp1;
		temp1 = temp1 -> next;
	}
	temp -> next = NULL;	
	free(temp1);	
}	
int main()
{
	ST *hptr = NULL;
	add_first(&hptr,1); 
	display(hptr);
	add_last(&hptr,2); 
	display(hptr);
	add_last(&hptr,3); 
	display(hptr);
	add_last(&hptr,4); 
	display(hptr);
	print_nth_last(hptr,2);
	reverse(&hptr);
	display(hptr);
	delete_last(&hptr);
	display(hptr);

	return 0;
}
