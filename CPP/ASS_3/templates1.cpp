#include <iostream>
using namespace std;
template <class type> void _swap (type &a , type &b )
{
    cout << "template fun "<< endl;
    type temp;
    temp = a ;
    a = b;
    b =temp;
}
int main()
{
    int x1 =10 ,x2 = 20;
    double d1 =100.456 ,d2 = 200.345;
    char ch1 = 'A', ch2 = 'B';
    cout << "X1:" << x1 << "   " << "X2:" << x2 << endl;
    _swap (x1,x2);
    cout << "X1:" << x1 << "   " << "X2:" << x2 << endl;
    cout << "ch1:" << ch1 << "   " << "ch2:" << ch2 << endl;
    _swap (ch1,ch2);
    cout << "ch1:" << ch1 << "   " << "ch2:" << ch2 << endl;
    cout << "d1:" << d1 << "   " << "d2:" << d2 << endl;
    _swap (d1,d2);
    cout << "d1:" << d1 << "   " << "d2:" << d2 << endl;
    return 0;
}
