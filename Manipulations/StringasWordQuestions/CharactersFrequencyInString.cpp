#include<iostream>
using namespace std;
#include<string.h>

int main()
{
#if 0 //Using char Array i.e., char x[] ="...."
        void func(char *x)
        {
                int freq[52]={0};//Initialize each element of array to ZERO

                while(*x)
                {
                        if(*x >= 'A' && *x <='z')
                        {
                                freq[*x - 65]++;
                        }

                        else if(*x >= 'a' && *x <='z')
                        {
                                freq[*x - 71]++;
                        }
                        x++;
                }

                for(int i=0;i<52;i++)
                {
                        if(freq[i] != 0)
                        {
                                if(i >=0 && i<=25) //Lower case letters[a-z]
                                {
                                        cout<<"character is: "<< (char)(i+65)<<freq[i]<<endl;
                                }
                                else if(i >=26 && i<=51) //Upper case letters[a-z]
                                {
                                        cout<<"character is: "<< (char)(i+71)<<freq[i]<<endl;
                                }
                        }
                }
        }

        char x[] ="AAAABBACCDAEzzyxx";
        func(x);  //func implementation is shown above
#endif

#if 1 //Using const char Ptr i.e., const char* x="...."
        const char *x ="AAAABBACCDAEzzyxx";  //Mixed characters[upper,lower case]
        int freq[52]={0};//Initialize each element of array to ZERO
//Instead of taking freq[52]. we can take 2 arrays like f1[26],f2[26] with f1 holding Lower case and f2 holding Upper case letters

        while(*x)
        {
                if(*x >= 'A' && *x <='Z') //Loading freq array using Lower case letters
                {
                        freq[*x - 65]++;
                }

                else if(*x >= 'a' && *x <='z') //Loading freq array using Upper case Letters
                {
                        freq[*x - 71]++;
                }
                x++;
        }

        for(int i=0;i<52;i++)
        {
                if(freq[i] != 0) //V.V.Imp, Eleminating the characters that are not present in the Array
                {
                        if(i >=0 && i<=25) //Lower case letters[a-z]
                        {
                                cout<<"character is: "<< (char)(i+65)<<freq[i]<<endl; //Typecasting from int to char,
                                                                                      //since we subtracted 97 above,we have to add that now
                        }
                        else if(i >=26 && i<=51) //Upper case letters[a-z]
                        {
                                cout<<"character is: "<< (char)(i+71)<<freq[i]<<endl; //Typecasting from int to char,
                                                                                      //since we subtracted 39 above,we have to add that now
                        }
                }
        }
#endif
}


