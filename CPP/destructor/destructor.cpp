#include <iostream>
using namespace std;
class A
{
        int *p;
        public:
        A()
        {
                cout << "constructor" <<endl;
                p = new int[5];
                cout << *p << endl;
                delete p; 
        }
        void del_fun()
        {
//                delete p;
                p = NULL;
                cout << p << endl;
        }
        ~A()
        {
                cout << "destructor" <<endl;
        }
};
void fun()
{
        A obj;
    //    obj.A();   // we cant call constructor explicitly
    //    obj.~A();  //we can call destructor multiple times but no use 
}
int main(void)
{

        fun();
        A *obj = new A;
        (*obj).del_fun();
        delete obj;
      return 0;
}
