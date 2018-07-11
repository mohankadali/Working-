#include <iostream>
using namespace std;
class A
{
    static int x ;
    public:
    static void fun()
    {
        cout << "x:" << x << endl;
    }
};
int  A :: x = 90;
int main(void)
{
    A obj;
    obj.fun();
    A obj1 ;
    return 0;
}
