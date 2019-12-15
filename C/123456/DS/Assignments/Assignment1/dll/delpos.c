#include "header.h"

extern node *head;

int del_pos (int pos)
{
	node  *temp1, *temp2;

	if(head == NULL) {
		return 0;
	}
	else {
		temp1 = head;
		temp2 = head->next;
		while (temp2->next != 0 && pos) {
			temp1 = temp1->next;
			temp2 = temp2->next;
			pos=pos-1;
		}
		temp1->prev->next = temp2;
		temp2->prev = temp1->prev;
		free (temp1);
	}
	return 1;
}
