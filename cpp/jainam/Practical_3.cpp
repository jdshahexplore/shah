#include<iostream>
using namespace std;

int main()
{
	int n,x=0;
	cout<<"enter any number = ";
	cin>>n;
	while(n>0)
	{
		x+=n%10;
		n/=10;
	}
	cout<<"Sum of digits = "<<x;
	return 0;
}
