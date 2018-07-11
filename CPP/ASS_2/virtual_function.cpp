#include<iostream>
using namespace std;
class base
{
    public :
              virtual void show()
//        void show()
        {
            cout << "base class: virtual show fun " << endl;
        }
        void display()
        {

            cout << "base class: display fun " << endl;
        }
};
class derived:public base
{
    public :
        void show()
        {
            cout << "derived class: show fun " << endl;
        }
        void display()
        {

            cout << "derived  class: display fun " << endl;
        }
};
int main(void)
{
    base base_object;
    base *ptr;
    ptr = & base_object;
    ptr -> show();
    ptr -> display();
    derived derived_object;
    ptr = & derived_object;
    ptr -> show();
    ptr -> display();

    return 0;
}
