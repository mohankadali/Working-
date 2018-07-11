#include <iostream>
using namespace std;
class V 
{
	public:
		V()
		{
			cout << "This is a Vehicle" << endl;
		}
};
class F
{
	public:
		F()
		{
			cout << "This is a 4 wheeler Vehicle" << endl;
		}
};
class Car: public F, public V
{

};
int main()
{   
	Car obj;
	return 0;
}
