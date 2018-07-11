#include <iostream>
using namespace std;
#include<cstring>

class A
{
	char *s;
	int l;
public:
	A()
	{
		s=NULL;
		l=0;
	}

	A(char *p)
	{
		l=strlen(p);
		s=new char[l+1];
		strcpy(s,p); //Deep copy concept
	}

	A operator+(const A &obj)
	{
		//if(this !=obj)
		//{
		A t;
		t.l=strlen(this->s)+strlen(obj.s);
		t.s=new char[t.l+1];
		strcpy(t.s,this->s);
		strcat(t.s,obj.s);
		//}
		return t;
	}

	void display()
	{
		cout<<s<<endl;
	}
};

int main()
{
	A c,a("Kadali"),b("Mohan");
	c=a+b;
	return 0;
}
