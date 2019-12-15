#include "header.h"

extern node *head;

int add_before_num (int ele, int num)
{
	node *nu, *temp;

	nu = (node*)malloc(sizeof(node));

	if(head == NULL) {
		head = nu;
		nu->data = ele;
		head->link = NULL;
	}
	else {
		temp = head;
		while (temp->link != 0 && temp->link->data != num) {
			temp = temp->link;
			}
		if (temp->link->data == num) {
		nu->link = temp->link;
		nu->data = ele;
		temp->link = nu;
		}
	}
}
