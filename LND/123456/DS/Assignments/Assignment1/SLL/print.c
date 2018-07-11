#include "header.h"

extern node *head;

void print()
{
	node *temp;
	temp = head;
	printf ("in print\n");
	while (temp != 0) {
		printf ("%d ",temp->data);
		temp = temp->link;
	}
    printf("\n");
}
