#include "header.h"

extern node *head;

int add_pen (int ele)
{
	node *nu, *temp1, *temp2;

	nu = (node*)malloc(sizeof(node));

	if(head == NULL) {
		head = nu;
		nu->data = ele;
		head->link = NULL;
	}
	else {
		temp1 = head;
		temp2 = head->link;
		while (temp2->link != 0) {
			temp2 = temp2->link;
			temp1 = temp1->link;
		}
		nu->link = temp1->link;
		nu->data = ele;
		temp1->link = nu;

	}
}
