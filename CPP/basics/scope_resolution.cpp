#include <iostream>
using namespace std;
int x = 20;
int main(void)
{
    int x = 10;
    cout << "local  x :" << x <<'\n' ;
    cout << "global x :" << ::x << '\n';


    return 0;
}
     
     
     
