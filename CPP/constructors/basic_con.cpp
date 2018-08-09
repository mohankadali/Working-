#include <iostream>
#include <string.h> 
#include <stdlib.h>
using namespace std;
class s 
{
        int roll;
        char *name;
        public:
        s();
        s(int, char*);
        void display();
};
void s :: display()
{
        cout << roll << endl;
        cout << name << endl;
}
s :: s(int num, char* n)
{
        roll = num;
        name = new char[strlen(n)+1];
        strcpy (name,n);
}
s :: s()
{
        roll = 0 ;
        name = new char[5];
        strcpy(name,"NONE");
}
int main()
{
        /*    s *ptr = (s*)malloc (sizeof(s)); // if we use malloc ,constructor will not be called implicitly
              ptr -> s();
              ptr -> display();
         */  

        s *ptr = NULL;
        ptr = new s(1, "MOHAN");
        ptr -> display();

        /*
           s s0;
           s0.display();
         */

        /* 
           s1.display();
           s s2(2, "krishna");
           s2.display();
         */

        return 0;
}
