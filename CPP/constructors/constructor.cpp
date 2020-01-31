#include <iostream>
using namespace std;
#if 0
class A{
	int x,y;
	public:
	A(int, int);
	void display();
};
A::A(int a, int b):x(a),y(b)
{

}
void A::display()
{
	cout << x << " " << y << endl;
}
int main(){
	A obj1(100,200);
	A obj2 (obj1); 
	obj2.display();

	return 0;
}
#endif
#if 0 
class A{
	int x,y;
	public:
	A(int a, int b):x(a),y(b){ //  we can assign a variables like this also 
	//	x = a+10;
	//	y = b+10;
	}
	void display(){
		cout << x << " " << y << endl;
	}
};
int main()
{
        A obj(10,20);
	obj.display();
	return 0;
}
#endif
#if 0
class A{
	mutable int x,y;
	public:
	A(){
		x = 10;
		y = 20;
	}
	void display() const
	{
		x = x + 5;
		cout << x << " " << y << endl;
	}
};
int main()
{
	const A obj;
	obj.display();
	return 0;
}
#endif

#if 1
class A{
	int x,y;
	public:
	A();
	void display();
};

A::A() // we should not use return type for constructor.... 
{
	cout << "constructor..." << endl;
	x = 10;
	y = 20;
}
void A::display()
{
	cout << x << y << endl;
}
int main()
{
	A obj;
	obj.display();
	return 0;
}
#endif
#if 0 
class A{
	int x,y;
	public:
	A() // we should not use return type for constructor.... 
	{
		cout << "constructor..." << endl;
		x = 10;
		y = 20;
	}
	void display()
	{
		cout << x << y << endl;
	}
};
int main()
{
	A obj;
	obj.display();
	return 0;
}
#endif






