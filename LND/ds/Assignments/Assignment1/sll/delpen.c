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
		temp2 = head->link;
		while (temp2->link->link != 0) {
			temp2 = temp2->link;
			temp1 = temp1->link;
		}
		temp1->link = temp2->link;
		free (temp2);
	}
	return 1;
}
