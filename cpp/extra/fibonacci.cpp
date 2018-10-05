#include<iostream>
using namespace std;
int main()
{
	int n,i,a=0,b=1,c=0;
	cout<<"enter limit = ";
	cin>>n;
	cout<<a<<"\t";
	for(i=1;i<n;i++)
	{
		cout<<b<<"\t";
		c=a+b;
		a=b;
		b=c;
	}
	return 0;
}
