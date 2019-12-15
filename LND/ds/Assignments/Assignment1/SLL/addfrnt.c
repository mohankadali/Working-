#include "header.h"

extern node *head;

int add_frnt (int ele)
{
	node *nu, *temp;

	nu = (node*)malloc(sizeof(node));

	if(head == NULL) {
		head = nu;
		nu->data = ele;
		head->link = NULL;
	}
	else {
		nu->link = head;
		nu->data = ele;
		head = nu;

	}
}
