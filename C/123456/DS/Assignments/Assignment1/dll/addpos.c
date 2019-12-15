#include "header.h"

extern node *head;

int add_pos (int ele, int pos)
{
	node *nu, *temp;

	nu = (node*)malloc(sizeof(node));

	if(head == NULL) {
		head = nu;
		nu->data = ele;
		head->next = NULL;
		head->prev = NULL;
	}
	else {
		temp = head;
		while (temp->next != 0 && pos) {
			temp = temp->next;
			pos=pos-1;
		}
		nu->next = temp->next;
		nu->data = ele;
		nu->prev = temp;
		temp->next = nu;

	}
}
