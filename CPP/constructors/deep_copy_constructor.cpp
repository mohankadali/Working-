#include<iostream>
#include <string.h>
using namespace std;
class A {
    private:
        char *p;
    public:
        A(const char *q){
            cout << "implicit copy" << endl;  
            p = new char[strlen(q)+1] ; 
            strcpy (p,q);
        }
        A(const A &obj){
        cout << "explicit copy constructor" << endl;
        p = new char [strlen(obj.p)+1];
        strcpy (p,obj.p);
        }
        void modify()
        {
            p[0] = 'W' ;
        }
        void display()
        {
            cout << "string : " << p << endl; 
        }

};
int main()
{
    A p1("hello");
    A p2 = p1;
  //  A p3("hello");
    //   p3 = p1 ;   // p3 = p1 means p3.A(p1) by default copy contructor will call.  
    p1 . modify();
    p1 . display();
    p2 . display();
    return 0;
}
