#include<iostream>
using namespace std;

int power(int b,int p)
{
	int i,x=1;
	for(i=1;i<=p;i++)
		x=x*b;
	return x;
}

int main()
{
	int b,p;
	cout<<"enter base and power = ";
	cin>>b>>p;
	cout<<b<<" raised to "<<p<<" = "<<power(b,p);
	return 0;
}
