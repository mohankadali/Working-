#include "header.h"

extern node *head;

void print()
{
	node *temp;
	temp = head;
	printf ("in print\n");
	while (temp != 0) {
		printf ("%d\t",temp->data);
		temp = temp->next;
	}
}
