#include<iostream>
using namespace std;

int lcm(int n1,int n2)
{
	int i,max,lcm;
	max=(n1>n2)?n1:n2;
	lcm=n1*n2;
	for(i=1;i<=max;i++)
	{
		if(n1%i==0 && n2%i==0)
			lcm=lcm/i;
	}
	return lcm;
}

int main()
{
	int n1,n2;
	cout<<"enter two numbers = ";
	cin>>n1>>n2;
	cout<<lcm(n1,n2);
	return 0;
}
