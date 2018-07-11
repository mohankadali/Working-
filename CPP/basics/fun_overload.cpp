#include <iostream>
using namespace std;

void sum(int a, int b=90);
void sum(int a, int b)
{
    cout << "sum :"<< a+b <<endl;
}
void sum(void)
{
    cout << "dummy sum fun " << endl;
}

int main(void)
{
    sum(10);
    sum();
    return 0;
}
