#include <iostream>
using namespace std;
int x = 10;
int get ()
{
        return x;
}
int main()
{
        int x =3;
        cout << x << endl;
        //    cout << get() << endl;
        cout << :: x << endl;

        return 0;
}
