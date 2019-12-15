#include "header.h"

extern node *head;

int del_mid ()
{
	node *temp1, *temp2, *temp3;


	if(head == NULL) {
		return 0;
	}
	else {
		temp1 = head;
		temp3 = head->link;
		temp2 = head;
		while (temp2->link != 0 && temp2->link->link != 0) {
			temp1 = temp1->link;
			temp3 = temp3->link;
			temp2 = temp2->link->link;
		}
		temp3->link = temp1->link;
		free(temp3);
	}
}
