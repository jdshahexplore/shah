#include<iostream>
using namespace std;
int main()
{
	int a,b,temp;
	cout<<"enter two numbers = "<<endl;
	cin>>a>>b;
	temp=a;
	a=b;
	b=temp;
	cout<<"after swapping"<<endl<<"a = "<<a<<endl<<"b = "<<b;
	return 0;
}
