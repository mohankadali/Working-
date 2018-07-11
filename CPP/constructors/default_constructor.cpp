#include <iostream>
using namespace std;
class A
{
    int x,y;
    public:
    A();
    void display();
};
A::A()
{
    cout << "constructor" <<endl;
    x = 10, y = 20;
}
void A::display()
{
    cout << "x:" << x << endl << "y:" << y << endl; 
}


int main(void)
{
    A obj;
    obj.display();
    return 0;
}
