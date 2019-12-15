#include "header.h"

extern node *head;

int add_after_num (int ele, int num)
{
	node *nu, *temp;

	nu = (node*)malloc(sizeof(node));

	if (head == NULL) {
		head = nu;
		nu->data = ele;
		head->link = NULL;
	}
	else {
		temp = head;
		while (temp->link != 0 && temp->data != num) {
			temp = temp->link;
		}
		if (temp->data == num){
		nu->link = temp->link;
		nu->data = ele;
		temp->link = nu;
		}
	}
	return 1;
}
