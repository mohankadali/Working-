#include <iostream>
using namespace std;
class A
{
    int x,y;
    public:
    A()
    {
        cout << "default constructor" << endl;
        x = 10, y = 20;
    }
    A(int a ,int b):x(a),y(b)
    {
        cout << "para constructor" << endl;
    }
    void display()
    {
        cout << "x:" << x << "  " << "y:" << y << endl; 
    }
};
int main(void)
{
    A *ptr = new A;
    ptr -> display();
    delete ptr;

    ptr = new A(123,234);
    ptr -> display();
    delete ptr;

    return 0;
}
