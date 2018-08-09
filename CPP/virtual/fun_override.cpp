#include <iostream>
using namespace std;
class base 
{
        public:
         	void fun(void)
                {
                        cout << "base class fun " << endl;
                }
};
class derived : public base
{
        public:
                void fun(void)
                {
                        cout << "derived class " << endl;
                }
};
int main()
{
        /*
           derived obj;
           obj.fun();
         */

        base *ptr ;

        derived obj;

        ptr = &obj;

        ptr-> fun();

        return 0;
}
