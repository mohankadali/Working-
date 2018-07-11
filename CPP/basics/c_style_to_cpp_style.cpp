#if 0
#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*Initializing a C-String */
    const char *a = "Testing"; 
    cout << "This is a C-String : "<< a << endl;

    /* This is how std::string s is assigned
     *        though a  C string ‘a’ */
    string s(a);  

    /* Now s is a std::string and a is a C-String */
    cout << "This is a std::string : "<< s << endl;
    s = s+s;
    cout << "This is a std::string : "<< s << endl;
    return 0;
}
#endif 

#if 1
#include<iostream>
#include <stdio.h>
#include<string> /* This header contains string class */
using namespace std;
int main()
{
    /* std::string initialized */
    string s = "Testing";  
    cout << "This is a std::string : "<< s << endl;

    /* Address of first character of std::string is 
     *        stored to char pointer a */
    char *a = &(s[0]); 
    /* Now 'a' has address of starting character
     *       of string */
    printf("%s\n", a);                 
    return 0;
}
#endif




