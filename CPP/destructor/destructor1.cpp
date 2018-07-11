#include <iostream>
using namespace std;
class A
{
    int *p;
    public:
    A()
    {
        cout << "constructor" <<endl;
    }
    ~A()
    {
        cout << "destructor" <<endl;
    }
};
int main(void)
{

    A *obj = new A;
    delete obj;
    return 0;
}
