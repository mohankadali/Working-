#include<iostream>
using namespace std;
struct st {

    mutable int x;
};
int main(void)
{
    const struct st var = {10};
    cout << var.x <<endl;
    var.x = 90;
    cout << var.x <<endl;
    return 0;
}
