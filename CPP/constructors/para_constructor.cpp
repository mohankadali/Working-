#include <iostream>
using namespace std;
class A
{
    int x,y;
    public:
    A(int, int);
};
//A::A(int a ,int b)
A::A(int a ,int b):x(a),y(b)
{
/*    x = a;
    y = b;
  */
    cout << "constructor" <<endl;
    cout << "x:" << x << endl << "y:" << y << endl; 
}


int main(void)
{
    A obj(1,2);
    return 0;
}
