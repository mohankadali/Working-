#include <iostream>
using namespace std;
int main(void)
{
        
    /*      int x =10;
            int &r = x;
            cout << "x address :"<< &x << '\n' ; // default address is  HEX form //
            cout << "reference variable r address :"<< &x << '\n' ;
            cout << "reference variable r:"<< r << '\n' ;
            r = 100 ;
            cout << "modified r value :"<< r << '\n' ;
            cout << "modified x value :"<< x << '\n' ;
          */


    /*    int x = 10;
          int &r ;// create new memory 
          r = x; // error,compiler unable to which variable create alias name, 
          */
    /*
          int x =10;
          int &r = 7; 
       */
    /*
          int x =10;
          int &p = x;
          int &q = p;
          int &r = q;
          cout << "r:" << r <<'\n';
       */  
int x =10;
int y =10;
int &rx = x;
//int &rx = y; // error due to reinitialization of reference variable
cout << rx <<endl;
//cout << ry <<endl;


    return 0;

}
