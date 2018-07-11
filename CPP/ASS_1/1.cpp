#include <iostream>
using namespace std;

class BOOK {

    private:
        int BOOKNO ;
        char BOOKTITLE[20];
        float PRICE;
        int N;
        void TOTAL_COST(int );
    public:
        void INPUT();
        void PURCHASE();
};
void BOOK::TOTAL_COST(int N)
{
    cout << "TOTAL COST:" << N*PRICE << endl;
}
void BOOK::INPUT()
{
    cout << "enter book number ...."<<endl;
    cin >> BOOKNO;
    cout << "enter book title ...."<<endl;
    cin >> BOOKTITLE;
    cout << "enter book price ...."<<endl;
    cin >> PRICE;
}
void BOOK::PURCHASE()
{

    cout <<" enter the no of copies required... " << endl;
    cin >> N ;
    TOTAL_COST(N);
}
int main()
{
    BOOK obj;
    obj.INPUT();
    obj.PURCHASE();

    return 0;
}
