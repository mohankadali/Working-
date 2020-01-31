#include <iostream>
using namespace std;
class A
{
	public:
//              virtual void fun()
		void fun()
		{
			cout << "base fun " << endl;
		}
};
class B : public A
{
	public:
		void fun()
		{
			cout << "derived fun " << endl;
		} 
};
int main()
{
	A *obj1;
	B obj2 ;
	obj1 = &obj2 ;
	cout << "obj1:" << &obj1 << "  " << "obj2:" << &obj2 << endl;	

	obj1->fun(); 
}

