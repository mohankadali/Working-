#include<iostream>
/* using is the key word to tell the compiler get all the standard lib from std */
using namespace std;
/* namespace creates separate memory for program elements like .bss , .data*/
namespace first
{
    int  x = 10;
}
namespace second
{
    int  x = 20;
}
int main(void)
{
/*
    using namespace first ;
    cout << x << endl;
    using namespace second ;
    cout << x << endl;
    */

/*
    {
        using namespace first ;
        cout << x <<endl;
    } 
    using namespace second ;
    cout << x <<endl;
*/
    

/*
    using first :: x;
    cout << "x:" << x << endl;
    using second :: x;
    cout << "x:" << x << endl;
*/


    return 0;
}










