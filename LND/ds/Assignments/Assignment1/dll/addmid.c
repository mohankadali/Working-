#include "header.h"

extern node *head;

int add_mid (int ele)
{
	node *nu, *temp1, *temp2;

	nu = (node*)malloc(sizeof(node));

	if(head == NULL) {
		head = nu;
		nu->data = ele;
		head->next = NULL;
		head->prev = NULL;
	}
	else {
		temp1 = head;
		temp2 = head;
		while (temp2->next != 0) {
			temp1 = temp1->next;
			temp2 = temp2->next->next;
		}
		nu->next = temp1->next;
		nu->data = ele;
		nu->prev = temp1;
		temp1->next = nu;

	}
}
