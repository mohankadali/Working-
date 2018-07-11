/* 
 * new returns address of the type 
 * new is a operator
 * if new fails it returns an exception  
*/


#include <iostream>
using namespace std;
int main(void)
{
    /*
       int *p = new int(1) ; 
       cout << "*p:" << *p <<endl;
       cout << "p:" << p <<endl;
       cout << "sizeof p:" << sizeof(p) <<endl;
       */

    /*
       int *p =  new int [5];
       for (int i;i<5;i++)
       cout << "p[" << i <<"]:" << p[i] <<endl;
       cout << "sizeof p:" << sizeof(p) <<endl;
       */
    /*
    int r = 3, c = 3;
    int **ptr = new int*[r];
    for (int i=0; i < r; i++)
        ptr[i] = new int [c];
    cout << "p:" << ptr << endl;
    int k =0;
    for (int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            ptr[i][j] = k++;
    for (int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cout << ptr[i][j] <<'\t';
    cout << endl;
*/
int *q = new int; // memory allocated 
int *p = new int(10) ; // memory allocated and initialized 

    return 0;
}




