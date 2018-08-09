#include <iostream>
#include <string.h>
using namespace std;
class st {
        public:
                int num;
                void fun()
                {
                        string str = "hello";
                        cout << "in fun str :" << str << endl;
                }
};
int main()
{
        st var ;
        var.num  = 100;
        cout << var.num <<endl;
        var.fun();    
        return 0;
}
