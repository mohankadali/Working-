#include "header.h"

extern node *head;

int del_frnt ()
{
	node  *temp;

	if(head == NULL) {
		return 0;
	}
	else {
		temp = head;
		head = head->next;
		head->prev = NULL;
		free(temp);
	}
}
