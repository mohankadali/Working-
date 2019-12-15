#include "header.h"

extern node *head;

int del_end ()
{
	node *temp1, *temp2;

	if(head == NULL) {
		return 0;
	}
	else if(head->next == NULL)
	{
		free(head);
	}
	else
	{
		temp1 = head;
		temp2 = head->next;
		while (temp2->next != NULL) {
			temp2 = temp2->next;
			temp1 = temp1->next;
		}
		temp1->next = NULL;
		free(temp2);
		//temp->next = NULL;
	}
	return 1;
}
