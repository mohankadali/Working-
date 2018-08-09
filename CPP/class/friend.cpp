#include <iostream>
#include <string.h>
using namespace std;
class st {
        int num;
        public:
        void set()
        {
                cout << "in set fun " <<endl;
                num  = 100;
        }
        friend void display(st &obj);
        //    friend void display(st obj);
};

void display(st &var)
        //void display(st var)
{
        cout << "in display fun num :" << var.num << endl;
}
int main()
{
        st var ;
        var.set();
        display(var);
        return 0;
}
