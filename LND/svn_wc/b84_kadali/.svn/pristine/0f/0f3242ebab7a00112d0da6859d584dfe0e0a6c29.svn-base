#include "header.h"

extern node *head;

int del_pen ()
{
	node  *temp1, *temp2;

	if(head == NULL) {
		return 0;
	}
	else {
		temp1 = head;
		temp2 = head->next;
		while (temp2->next != 0) {
			temp2 = temp2->next;
			temp1 = temp1->next;
		}
		temp1->prev->next = temp2;
		temp2->prev = temp1->prev;
		free (temp1);
	}
}
