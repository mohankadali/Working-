#include <iostream>
using namespace std;

double test(int a) {
    if( a > 0 ) {
        return (a);
    }
    throw "X";
}

int main () {
    int x = 10;
    int y = 0;
    double z = 0;

    try 
    {
        z = test(x);
        cout << z << endl;
        z = test(y);
        cout << z << endl;
    }
    catch (const char* msg) 
    {
        cout << msg << endl;
    }

    return 0;
}
