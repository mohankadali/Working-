#include "header.h"

extern node *head;

int add_end (int ele)
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
			while (temp->link != 0) {
				temp = temp->link;
			}
			nu->link = temp->link;
			nu->data = ele;
			temp->link = nu;

		}
}
