#include <iostream>
#include <string.h>
using namespace std;
class A {
	private:
		char *p;
	public:
		A(const char *q){
			cout << "before  p :" << p << endl;
			cout << "before  q :" << q << endl;
			p = new char[strlen(q)+1] ; 
			strcpy (p,q);
			cout << "after p :" << p << endl;
			cout << "after q :" << q << endl;
		}
		void modify()
		{
			p[0] = 'W' ;
		}
		void display()
		{
			cout << "string : " << p << endl; 
		}
};
int main()
{
	A p1("hello"); 
	A p2 ( p1 ); // Copy constructor is called here
	p1 . modify();
	p1 . display();
	p2 . display();
	return 0;
}
