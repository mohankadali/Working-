#include<iostream>
using namespace std;
#include<string.h>

int main()
{
        const char *x="Global Edge is a MNC Global Edge is located in Tech Park Tech Park is Good";
        char y[20][10]; //2d array with rows = Number of words[space+1]
        int j = 0; //rows
        int k = 0; //columns

        while (*x)
        {
                if(*x ==' ' || *x == '.' || *x == '\n' || *x == '\t')
                {
                        y[j][k]='\0'; //Completion of Each WORD
                        j++; //Increment rows
                        k=0; //Reset columns to 0

                        x++; //V.V.Imp, Whenever these characters come,Move the 'x' position to next position
                }

                if(*x != '\0')
                {
                        y[j][k]= *x; //Filling the 2d array
                        k++; //increment columns
                }
                x++;
        }
        y[j][k]='\0'; //Completion of Last WORD

/*************************************************************
6steps to get the count of unique words in a sentence
int flag = false;
int count =1; //step1

for(int b=0;b<=j;b++) //step2
{
if(a==b)
continue; //step3
if( strcmp(y[a],y[b])==0 ) //duplicate words
{
flag =true;
break; //step4
}
else //unique words,step5
{
flag=false;
}
}

if(flag == false) //Number of unique words
{
count++; //step6
cout<<"Unique Words are: "<<y[a]<<endl;
}
*************************************************************/

        bool flag = false;
        int count=1; //V.V.V.Imp,Make count as 1
        for(int a=0;a<=j;a++) //condition check with rows only
        {
                for(int b=0;b<=j;b++) //V.V.V.Imp step, b should always start from Zero
                {
                        if(a==b) //V.V.V.Imp step, Check for the same position and skip that WORD
                        {
                                continue;
                        }

                        if( strcmp(y[a],y[b])==0 ) //duplicate words
                        {
                                flag =true;
                                break; //V.V.V.Imp step
                        }
                        else //unique words
                        {
                                flag=false;
                        }
                }
                if(flag == false) //Number of unique words
                {
                        count++;
                        cout<<"Unique Words are: "<<y[a]<<endl;
                }
                if(flag == true) //Duplicate words
                {
                        cout<<"Duplicate Words are: "<<y[a]<<endl;
                }
        }
        cout<<"Count  of Unique Words: "<<count<<endl; //V.V.Imp
}
