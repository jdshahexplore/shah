#include<iostream>
using namespace std;

int gcd(int n1,int n2)
{
	if(n2==0)
		return n1;
	else
		return gcd(n2,n1%n2);
}

int main()
{
	int n1,n2;
	cout<<"enter two numbers = ";
	cin>>n1>>n2;
	if(n1>=n2)
		cout<<gcd(n1,n2);
	else
		cout<<gcd(n2,n1);
	return 0;
}
