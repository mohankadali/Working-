#include "header.h"

extern node *head;

int del_end ()
{
	node *temp;

	if(head == NULL) {
		return 0;
	}
	else if(head->link==NULL)
	{
		free(head);
	}
	else
	{
		temp = head;
		while (temp->link != 0) {
			temp = temp->link;
		}
		free(temp->link);
		temp->link = NULL;
	}
	return 1;
}
