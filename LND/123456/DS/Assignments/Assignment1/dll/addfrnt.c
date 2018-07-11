#include "header.h"

extern node *head;

int add_frnt (int ele)
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
		nu->next = head;
		nu->prev = NULL;
		nu->data = ele;
		head = nu;

	}
}
