#include "header.h"

extern node *head;

int del_mid ()
{
	node *temp1, *temp2, *temp3;


	if(head == NULL) {
		return 0;
	}
	else {
		temp1 = head;
		temp3 = head->next;
		temp2 = head;
		while (temp2->next != 0 && temp2->next->next != 0) {
			temp1 = temp1->next;
			temp3 = temp3->next;
			temp2 = temp2->next->next;
		}
		temp1->prev->next = temp3;
		temp3->prev = temp1->prev;
		free(temp1);
	}
	return 1;
}
