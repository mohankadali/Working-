#include "header.h"

extern node *head;

int add_before_num (int ele, int num)
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
		while (temp->next != 0 && temp->next->data != num) {
			temp = temp->next;
			}
		if (temp->next->data == num) {
		nu->next = temp->next;
		nu->data = ele;
		nu->prev = temp;
		temp->next = nu;
		}
	}
}
