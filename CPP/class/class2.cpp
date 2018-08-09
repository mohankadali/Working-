#include <iostream>
#include <string.h>
using namespace std;

class st {
        public:
                int num;
                void set()
                {
                        num  = 100;

                }
                void display()
                {
                        cout << "in display fun num :" << num << endl;
                }
};
void check(st &var1 )
{
        cout << "in fun" << &var1 <<endl;
        cout << "in check fun num :" << var1.num << endl;
}
int main()
{
        st var ;
        cout<< "in main" << &var << endl;
        var.set();
        var.display();
        check(var);
        return 0;
}
