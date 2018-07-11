#include <iostream>
using namespace std;
int& fun(int &x)
{
x = x*x;
return x;
}
int main(void)
{
    int y = 3;
    cout << fun(y) << endl;
    int z = fun(y);
    cout << z << endl;
    return 0;
}
