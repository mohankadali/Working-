#include <iostream>
using namespace std;
class A
{
        int num;
        public:
        void set (int a)
        {
                cout << "in set fun this address :"<< this <<endl;
                this -> num  = a ;
        }
        friend void display (A var); 
};
void display (A var)
{
        cout << "in display fun" << endl;
        cout << "this->x:" << var.num << endl;  
} 
int main(void)
{
        A obj;
        obj.set(1);
        cout << "in main this address :"<< &obj <<endl;
        display (obj);

        return 0;
}
