#include <iostream>
#include <string.h>
using namespace std;

struct st {
//            private:
        int num;
        public:
        void set()
        {
                num  = 100;

        }
        void display()
        {
                cout << "in display fun num :" << num << endl;
        }
};
void check(st var )
{
        cout << "in check fun num :" << var.num << endl;
}
int main()
{
        st var ;
        var.set();
        var.display();
        check(var);
        return 0;
}
