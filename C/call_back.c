#include<stdio.h> 

void A()
{

printf("hi \n");

}

void B(void (*fun)())
{

(*fun)();

}

int main() 
{ 
	void (*fun)()  = &A;
	B(fun);
	return 0; 
} 
