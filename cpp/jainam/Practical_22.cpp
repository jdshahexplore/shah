#include<iostream>
#include<string.h>
using namespace std;

class String
{
	char str[20];
	public:
		String() {str[0]='\0';}
		void getdata()
		{
			cout<<"Enter string = ";
			cin>>str;
		}
		void putdata() {cout<<"String = "<<str<<endl<<endl;}
		void operator +(String &);
		String operator =(String);
		int length();
		int operator ==(String);
};

void String::operator +(String & s2)
{
	strcat(str,s2.str);
}

String String::operator =(String s1)
{
	String s;
	strcpy(s.str,s1.str);
	return s;
}

int String::length()
{
	int i;
	for(i=0;str[i]!='\0';i++);
	return i;
}

int String::operator ==(String s2)
{
	if(strcmp(str,s2.str)==0)
		return 0;
	else
		return 1;
}

int main()
{
	String s1,s2;
	int c,l;
	cout<<"1: Concat string"<<endl;
	cout<<"2: Copy string"<<endl;
	cout<<"3: Length of string"<<endl;
	cout<<"4: Compare string"<<endl;
	cout<<"5: Exit"<<endl;
	read:
	cout<<"Enter choice = ";
	cin>>c;
	switch(c)
	{
		case 1:
			s1.getdata();
			s2.getdata();
			s1+s2;
			s1.putdata();
			goto read;
		case 2:
			s1.getdata();
			s2=s1;
			s2.putdata();
			goto read;
		case 3:
			s1.getdata();
			l=s1.length();
			cout<<"Length of string = "<<l<<endl<<endl;
			goto read;
		case 4:
			s1.getdata();
			s2.getdata();
			l=(s1==s2);
			if(l==0)
				cout<<"Equal Strings"<<endl<<endl;
			else
				cout<<"Unequal Strings"<<endl<<endl;
			goto read;
		case 5:
			break;
		default:
			cout<<"Wrong Choice"<<endl<<endl;
			goto read;
	}
	return 0;
}
