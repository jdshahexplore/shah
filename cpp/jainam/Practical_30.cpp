#include<iostream>
using namespace std;

template<class T>
void swaping(T &a,T &b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
}

int main()
{
	int a,b;
	cout<<"Enter two integers = ";
	cin>>a>>b;
	swaping(a,b);
	cout<<"------Swapping integer data------"<<endl;
	cout<<"a = "<<a<<endl<<"b = "<<b<<endl;
	float c,d;
	cout<<"Enter two float numbers = ";
	cin>>c>>d;
	swaping(c,d);
	cout<<"------Swapping floating data------"<<endl;
	cout<<"c = "<<c<<endl<<"d = "<<d<<endl;

	return 0;
}
