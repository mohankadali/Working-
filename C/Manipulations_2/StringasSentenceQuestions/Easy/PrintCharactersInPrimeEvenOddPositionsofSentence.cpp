#include<iostream>
using namespace std;


//For positions questions,Use array implementation only, not pointers
int main()
{
        char x[]="Global Edge is a MNC";
        for(int num =2;x[num];num++) //Here num is index of the array, that starts from 0
        {

#if 0 //Enable this, if you want to avoid/skip spaces
                if(x[num] == ' ')
                        continue;
#endif

#if 1 //Prime Number Implementation
                int count=0;
                for(int i=1;i<=num;i++)
                {
                        if(num%i==0)
                        {
                                count++;
                        }
                }
                if(count == 2)
                {
                        cout<<x[num-1]<<endl; //x[num-1],since the alphabets are starting from 1 but index(num) starts from 0
                }
#endif

#if 0
                if(num%2 ==0 )
                        cout<<x[num]<<endl;;
                else if(num%2 ==1)
                        cout<<x[num]<<endl;
#endif
        }
}
