/*
 *  inline is just a request to the compiler 
 *  if  accept the request it acts as a macro 
 *  if rejects acts as a normal fun 
 *  its not a order to be like that    
 *  with the help of object code size we can say that inline request accepted or not 
 *  if we define a fun with in the class implicitly its a inline fun       
*/


#include <iostream>
using namespace std;
inline int fun (int a ,int b)
{
    return a+b;
}

int main(void)
{
    int x = 10, y = 20;
    int z = fun ( x,y );
    cout << "z:" << z <<endl; 
    return 0;
}






