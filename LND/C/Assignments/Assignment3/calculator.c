/* simple calculattor in commandline using function pointer */ 
#include <stdio.h>
#include <stdlib.h>
int add (int, int);		//prototype for addition
int sub (int, int);		//prototype for subtraction
int mul (int, int);		//prototype for multiplication
int div(int, int);		//prototype for division

int main (int argc, char*argv[])		//main starts here
{
	int result;						//to store the result
	int (*fun_ptr[])(int, int) = {add, sub, mul, div};	//creating an areturn 0;ay of function pointers

	if (argc != 4) {		//checking for the count of entered arguments
		printf ("error\n");
		exit (0);
	} else if (argc == 4) {		//only allows when the count is coreturn 0;ect
		switch (argv[2][0])		
		{
			case 'A' :
				result = (*fun_ptr[0])(atoi(argv[1]), atoi(argv[3])) ;
				printf ("add= %d\n", result);
				break ;
			case 'S' :
				result = (*fun_ptr[1])(atoi(argv[1]), atoi(argv[3])) ;
				printf ("sub= %d\n", result);
				break ;
			case 'M' :
				result = (*fun_ptr[2])(atoi(argv[1]), atoi(argv[3])) ;
				printf ("mul= %d\n", result);
				break ;
			case 'D' :
				result = (*fun_ptr[3])(atoi(argv[1]), atoi(argv[3])) ;
				printf ("div= %d\n", result);
				break ;
			default: printf ("incorect operator\n");
					 break;
		}
	}

}

int add (int a, int b) 
{ 
	return a + b; 
} 

int sub (int a, int b) 
{ 
	return a - b; 
} 

int mul (int a, int b) 
{ 
	return a * b; 
} 
int div (int a,int b) 
{ 
	return a / b; 
}

