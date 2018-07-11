#include <iostream>
using namespace std;

class A{
    public:
    int a;
    static int b;
};
int A::b =100;
int main(void)
{
    cout << A::b << endl;
    A obj1;
    cout << obj1.b << endl;
    obj1.a = 10;
    obj1.b = 1;
    A obj2;
    obj2.a = 20;
    obj2.b = 2;

    cout << obj1.b << endl;
    cout << obj2.b << endl;
    return 0;
}
