#include "header.h"

extern node *head;

int del_before (int pos)
{
	node *temp1, *temp2;


	if(head == NULL) {
		return 0;
	}
	else {
		temp1 = head;
		temp2 = head->link;
		pos=pos-1;
		while (temp2->link != 0 && pos) {
			temp1 = temp1->link;
			temp2 = temp2->link;
			pos=pos-1;
		}
		temp1->link = temp2->link;
		free(temp2);
	}
	return 1;
}
