#include <iostream>
using namespace std;
int * foo()
{
        int a = 5;
        delete(&a);
        return &a;
}

int main()
{
        int* p = foo();
        cout << *p;
        *p = 8;
          cout << *p;
}
