
				// *******  RED - BLACK TREE ****** //


#include "header.h"							// ****** including header file  ****** //

int main()
{
	p = "Welcome to RB-TREE insertion";				// ******  Headline of the RB-TREE ****** //
	printf( GREEN "\n\n\n\t\t"  "\033[3m%s\033[0m\n\n\n", p);	// ******  italic view of the string with GREEN color ****** //
	printf(RESET);

	//printf(GREEN "\n\n\t\t\tWelcome to RB-TREE insertion\n\n"  RESET "\n"  );

	root  =  dummy_rbt_node () ;					// ****** first time inserting dummy node to root  ****** //
	if (root == NULL){
		exit (EXIT_FAILURE);
	}
	while (1){
		printf ("choose one option from the list\n");
		printf (" 1  ==>  insert\n 2  ==>  printing\n 3  ==>  exit\n"); // ****** choosig the required operation ***** //
		printf ("\nEnter your choice : ");

		fgets ((char*)&choice, MAX, stdin); 			// *****  getting the option using fgets function ***** //
		choice = atoi ((char*)&choice);				// *****  converting string to interger value using  atoi fun ***** // 

		switch (choice){
			case 1:
				printf ("\nEnter the number to be inserted : ");
				fgets ((char*)&num, MAX, stdin);
				num = atoi ((char*)&num);
				insert_rbt_node ();			// ***** inserting the node function ***** //
				break;
			case 2:
				printf ("\n");
				rbt_preorder_traversal (root);		// ***** printing in preorder traversal **** //
				printf ("\n");
				break;
			case 3:
				printf ("Exit  successfully \n");
				exit (1);
			default:
				printf ("wrong choice\n");

		}
	}
	return 0;
}
