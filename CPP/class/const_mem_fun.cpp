#include <iostream>
using namespace std;
class A
{
        private:
        int num;
        public:
        void set (int a)
        {
                num  = a ;
        }
        void display ()// const 
        {
                num = num + 5;
                cout << "modified data :" << num << endl;  
        } 
};
int main(void)
{
        A obj;
        obj.set(1);
        obj.display();
        return 0;
}
